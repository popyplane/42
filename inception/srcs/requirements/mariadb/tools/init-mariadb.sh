#!/bin/bash
# This is the shebang line that specifies which interpreter to use (bash)

if [ ! -d "/var/lib/mysql/mysql" ]; then
    # This checks if the MySQL data directory exists. If not, this is a first-time initialization
    
    echo "Initializing MariaDB database..."
    mysql_install_db --user=mysql
    # This initializes the database system files with mysql user as owner
    
    # Create a temporary SQL file for better error handling
    TMP_SQL=$(mktemp)
    # Creates a temporary file and stores its path in TMP_SQL variable
    
    cat > "$TMP_SQL" <<EOF
USE mysql;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF
    # Uses a "here document" to write SQL commands to the temporary file
    # The commands select mysql database, create WordPress database, create user,
    # grant privileges, set root password, and apply changes
    
    # Execute the SQL file with bootstrap
    mysqld --user=mysql --bootstrap < "$TMP_SQL"
    # Runs mysqld in bootstrap mode (special startup mode for initialization)
    # and passes our SQL commands as input
    
    SQL_RESULT=$?
    # Captures the exit status of the previous command
    
    if [ $SQL_RESULT -eq 0 ]; then
        # If the SQL commands executed successfully (exit code 0)
        echo "MariaDB database initialized successfully with user '${MYSQL_USER}' and database '${MYSQL_DATABASE}'"
    else
        # If there was an error with the first approach
        echo "ERROR: Failed to initialize MariaDB database (exit code: $SQL_RESULT)"
        # Try an alternative approach for older MariaDB versions
        
        mysql_install_db --user=mysql
        # Reinitialize the database files
        
        # Create another temporary SQL file with alternative syntax
        ALT_SQL=$(mktemp)
        cat > "$ALT_SQL" <<EOF
USE mysql;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER '${MYSQL_USER}'@'%';
SET PASSWORD FOR '${MYSQL_USER}'@'%' = PASSWORD('${MYSQL_PASSWORD}');
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF
        # This is an alternative syntax for creating users in older MariaDB versions
        # It creates the user first, then sets the password separately
        
        mysqld --user=mysql --bootstrap < "$ALT_SQL"
        ALT_RESULT=$?
        # Run the alternative commands and capture exit status
        
        if [ $ALT_RESULT -eq 0 ]; then
            echo "MariaDB database initialized successfully with alternative approach"
        else
            echo "ERROR: Both initialization approaches failed"
            exit 1
            # Exit with error if both approaches fail
        fi
    fi
    
    # Cleanup
    rm -f "$TMP_SQL" "$ALT_SQL" 2>/dev/null
    # Remove temporary files, suppress errors if they don't exist
else
    echo "MariaDB database directory already exists, skipping initialization"
    # Skip initialization if database already exists
fi

# Add a final check to confirm user creation before starting the main process
echo "Final check: Starting temporary MariaDB server to verify user creation"
mysqld --user=mysql --skip-networking &
# Start a temporary MariaDB server in background with networking disabled for safety
# The & makes this run in the background

TEMP_PID=$!
# Store the process ID of the background server
sleep 5  # Wait for server to start

# Check if user exists by querying the user table
mysql -u root --password="${MYSQL_ROOT_PASSWORD}" -e "SELECT User, Host FROM mysql.user;" || echo "Failed to check users"
mysql -u root --password="${MYSQL_ROOT_PASSWORD}" -e "SHOW DATABASES;" || echo "Failed to check databases"

# Attempt to create user one more time if not found
if ! mysql -u root --password="${MYSQL_ROOT_PASSWORD}" -e "SELECT User FROM mysql.user WHERE User='${MYSQL_USER}';" | grep -q "${MYSQL_USER}"; then
    # If the user isn't found in the previous query (grep returns nothing)
    echo "User not found, creating one more time..."
    mysql -u root --password="${MYSQL_ROOT_PASSWORD}" <<EOF
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF
    # Connect to the running server and create the user directly
fi

# Kill temporary server
kill $TEMP_PID
# Send termination signal to the temporary server
wait $TEMP_PID 2>/dev/null
# Wait for the process to fully terminate, suppress any error messages

echo "Starting main MariaDB process..."
exec "$@"
# Replace the current shell with the command passed to the script
# This is how the container's main process (mysqld) gets started
# "$@" represents all arguments passed to the script
