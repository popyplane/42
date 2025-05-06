#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

# Output all commands being executed (helpful for debugging)
set -x

# Colors for better readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "=== Starting MariaDB Initialization Script ==="
echo "Current user: $(whoami)"
echo "Current directory: $(pwd)"

# Debug: Print environment variables (excluding passwords)
echo "${YELLOW}=== Environment Debug ===${NC}"
echo "${YELLOW}MYSQL_DATABASE: ${MYSQL_DATABASE:-not set}${NC}"
echo "${YELLOW}MYSQL_USER: ${MYSQL_USER:-not set}${NC}"
echo "${YELLOW}Database and User variables present: $([[ -n $MYSQL_DATABASE && -n $MYSQL_USER && -n $MYSQL_PASSWORD && -n $MYSQL_ROOT_PASSWORD ]] && echo 'YES' || echo 'NO')${NC}"
echo "${YELLOW}=======================${NC}" 

# Ensure all required environment variables are set
if [[ -z "$MYSQL_DATABASE" || -z "$MYSQL_USER" || -z "$MYSQL_PASSWORD" || -z "$MYSQL_ROOT_PASSWORD" ]]; then
    echo "${RED}ERROR: Required environment variables are not set!${NC}"
    echo "${YELLOW}Make sure MYSQL_DATABASE, MYSQL_USER, MYSQL_PASSWORD, and MYSQL_ROOT_PASSWORD are defined.${NC}"
    exit 1
fi

echo "${GREEN}All required environment variables are set.${NC}"

# Only initialize if this is the first start
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "${YELLOW}Initializing MariaDB database...${NC}"
    
    # Print directory structure for debugging
    echo "${YELLOW}Directory structure before initialization:${NC}"
    ls -la /var/lib/mysql/
    
    echo "${YELLOW}Running mysql_install_db...${NC}"
    # Initialize the database
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    echo "${YELLOW}Directory structure after initialization:${NC}"
    ls -la /var/lib/mysql/
    
    # Create a temporary SQL file for setup
    TMP_SQL=$(mktemp)
    cat > "$TMP_SQL" <<EOF
USE mysql;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    echo "${YELLOW}Executing SQL setup with mysqld bootstrap...${NC}"
    # Show what we're executing without showing passwords
    echo "${YELLOW}Contents of SQL script (passwords redacted):${NC}"
    cat "$TMP_SQL" | sed 's/IDENTIFIED BY .*/IDENTIFIED BY [REDACTED];/g'
    
    echo "${YELLOW}Starting mysqld in bootstrap mode...${NC}"
    
    # Turn off 'set -e' temporarily so we can see the error if mysqld fails
    set +e
    
    # Start mysqld in bootstrap mode with error output
    mysqld --user=mysql --bootstrap < "$TMP_SQL" 2>&1
    BOOTSTRAP_RESULT=$?
    
    # Turn 'set -e' back on
    set -e
    
    if [ $BOOTSTRAP_RESULT -ne 0 ]; then
        echo "${RED}ERROR: Bootstrap mode failed with exit code $BOOTSTRAP_RESULT${NC}"
        echo "${YELLOW}This might be due to a syntax error in the SQL script or mysqld bootstrap mode failure${NC}"
        echo "${YELLOW}Let's try a different approach...${NC}"
        
        # Alternative approach - start mysqld_safe in background, wait, then run SQL
        echo "${YELLOW}Starting mysqld_safe in background..."
        mysqld_safe --user=mysql &
        
        # Wait for MySQL to be ready
        echo "${YELLOW}Waiting for MySQL to start...${NC}"
        for i in {1..30}; do
            if mysqladmin ping >/dev/null 2>&1; then
                echo "${GREEN}MySQL is up and running!${NC}"
                break
            fi
            echo "${YELLOW}Waiting... ($i/30)${NC}"
            sleep 1
        done
        
        # Execute SQL commands
        echo "${YELLOW}Executing SQL setup directly...${NC}"
        mysql -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
        mysql -e "CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
        mysql -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';"
        mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
        mysql -e "FLUSH PRIVILEGES;"
        
        # Shutdown MySQL properly
        echo "${YELLOW}Shutting down MySQL...${NC}"
        mysqladmin -u root shutdown
        
        # Wait for MySQL to shut down
        echo "${YELLOW}Waiting for MySQL to stop...${NC}"
        while mysqladmin ping >/dev/null 2>&1; do
            echo "${YELLOW}Still waiting for MySQL to stop...${NC}"
            sleep 1
        done
    fi
    
    # Cleanup
    rm -f "$TMP_SQL"
    
    echo "${GREEN}MariaDB database initialized successfully!${NC}"
else
    echo "${RED}MariaDB database already initialized. Skipping initialization.${NC}"
fi

echo "${YELLOW}Starting MariaDB server with command: $@${NC}"
echo "${GREEN}=== End of initialization script ===${NC}"

# Remove -e before starting mysqld so it can handle its own errors
set +e

# Run the passed command (should be mysqld)
exec "$@"