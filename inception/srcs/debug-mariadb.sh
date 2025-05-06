#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

# Colors for better readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== MariaDB Debug Script ===${NC}"

# Clean up any existing test containers/volumes
echo -e "${YELLOW}Cleaning up existing resources...${NC}"
docker stop mariadb-debug-container 2>/dev/null || true
docker rm mariadb-debug-container 2>/dev/null || true
docker volume rm mariadb_debug_vol 2>/dev/null || true
docker rmi mariadb-debug -f 2>/dev/null || true

# Copy fixed scripts to the right locations
echo -e "${YELLOW}Copying fixed initialization script...${NC}"
# Create backup of the original script
cp srcs/requirements/mariadb/tools/init-mariadb.sh srcs/requirements/mariadb/tools/init-mariadb.sh.bak
# Copy the fixed script
cat > srcs/requirements/mariadb/tools/init-mariadb.sh <<'EOF'
#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

# Output all commands being executed (helpful for debugging)
set -x

echo "=== Starting MariaDB Initialization Script ==="
echo "Current user: $(whoami)"
echo "Current directory: $(pwd)"

# Debug: Print environment variables (excluding passwords)
echo "=== Environment Debug ==="
echo "MYSQL_DATABASE: ${MYSQL_DATABASE:-not set}"
echo "MYSQL_USER: ${MYSQL_USER:-not set}"
echo "Database and User variables present: $([[ -n $MYSQL_DATABASE && -n $MYSQL_USER && -n $MYSQL_PASSWORD && -n $MYSQL_ROOT_PASSWORD ]] && echo 'YES' || echo 'NO')"
echo "=======================" 

# Ensure all required environment variables are set
if [[ -z "$MYSQL_DATABASE" || -z "$MYSQL_USER" || -z "$MYSQL_PASSWORD" || -z "$MYSQL_ROOT_PASSWORD" ]]; then
    echo "ERROR: Required environment variables are not set!"
    echo "Make sure MYSQL_DATABASE, MYSQL_USER, MYSQL_PASSWORD, and MYSQL_ROOT_PASSWORD are defined."
    exit 1
fi

echo "All required environment variables are set."

# Only initialize if this is the first start
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    
    # Print directory structure for debugging
    echo "Directory structure before initialization:"
    ls -la /var/lib/mysql/
    
    echo "Running mysql_install_db..."
    # Initialize the database
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    echo "Directory structure after initialization:"
    ls -la /var/lib/mysql/
    
    # We'll start mysqld_safe in background, wait, then run SQL
    echo "Starting mysqld_safe in background..."
    mysqld_safe --user=mysql &
    
    # Wait for MySQL to be ready
    echo "Waiting for MySQL to start..."
    for i in {1..30}; do
        if mysqladmin ping >/dev/null 2>&1; then
            echo "MySQL is up and running!"
            break
        fi
        echo "Waiting... ($i/30)"
        sleep 1
    done
    
    # Execute SQL commands
    echo "Executing SQL setup directly..."
    mysql -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
    mysql -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
    mysql -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';"
    mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
    mysql -e "FLUSH PRIVILEGES;"
    
    # Shutdown MySQL properly
    echo "Shutting down MySQL..."
    mysqladmin -u root shutdown
    
    # Wait for MySQL to shut down
    echo "Waiting for MySQL to stop..."
    while mysqladmin ping >/dev/null 2>&1; do
        echo "Still waiting for MySQL to stop..."
        sleep 1
    done
    
    echo "MariaDB database initialized successfully!"
else
    echo "MariaDB database already initialized. Skipping initialization."
fi

echo "Starting MariaDB server with command: $@"
echo "=== End of initialization script ==="

# Remove -e before starting mysqld so it can handle its own errors
set +e

# Run the passed command (should be mysqld)
exec "$@"
EOF

# Make sure the script is executable
chmod +x srcs/requirements/mariadb/tools/init-mariadb.sh

# Ensure script has Unix line endings
echo -e "${YELLOW}Converting script to Unix line endings...${NC}"
if command -v dos2unix &> /dev/null; then
    dos2unix srcs/requirements/mariadb/tools/init-mariadb.sh
else
    # If dos2unix is not available, use sed as fallback
    sed -i 's/\r$//' srcs/requirements/mariadb/tools/init-mariadb.sh
fi

# Build the MariaDB debug image
echo -e "${YELLOW}Building MariaDB image...${NC}"
docker build -t mariadb-debug srcs/requirements/mariadb

# Create volume for MariaDB data
echo -e "${YELLOW}Creating volume for MariaDB data...${NC}"
docker volume create mariadb_debug_vol

# Run the container in interactive mode
echo -e "${GREEN}Starting MariaDB container in interactive mode...${NC}"
echo -e "${YELLOW}You'll see debug output. When the container is ready, try connecting to it.${NC}"

docker run --name mariadb-debug-container \
    --env-file srcs/.env \
    -p 3306:3306 \
    --mount type=volume,source=mariadb_debug_vol,target=/var/lib/mysql \
    mariadb-debug

echo -e "${YELLOW}Container exited. Checking container status:${NC}"
docker inspect -f '{{.State.Status}}' mariadb-debug-container
echo -e "${YELLOW}Container exit code:${NC}"
docker inspect -f '{{.State.ExitCode}}' mariadb-debug-container

echo -e "${YELLOW}=== Test if MySQL is working properly ===${NC}"
echo -e "${GREEN}Restarting container to test connection...${NC}"

docker start mariadb-debug-container
sleep 5  # Give MySQL time to start

# Test MySQL connection
echo -e "${YELLOW}Testing MySQL connection...${NC}"
docker exec -i mariadb-debug-container mysql -u${MYSQL_USER} -p${MYSQL_PASSWORD} -e "SHOW DATABASES;" 2>/dev/null || echo -e "${RED}MySQL connection failed${NC}"

echo -e "${YELLOW}=== Debug Complete ===${NC}"
echo -e "${GREEN}If everything worked, you can now use these commands:${NC}"
echo "docker exec -it mariadb-debug-container mysql -u root -p"  # To connect as root
echo "docker exec -it mariadb-debug-container mysql -u wpuser -p" # To connect as wpuser