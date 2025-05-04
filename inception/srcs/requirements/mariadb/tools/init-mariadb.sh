#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

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

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    
    # Print directory structure for debugging
    echo "Directory structure before initialization:"
    ls -la /var/lib/mysql/
    
    # Initialize the database
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    INSTALL_RESULT=$?
    if [ $INSTALL_RESULT -ne 0 ]; then
        echo "ERROR: mysql_install_db failed with exit code $INSTALL_RESULT"
        exit 1
    fi
    
    echo "Directory structure after initialization:"
    ls -la /var/lib/mysql/
    
    # Create a temporary SQL file for setup
    TMP_SQL=$(mktemp)
    cat > "$TMP_SQL" <<EOF
USE mysql;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    echo "Executing SQL setup with mysqld bootstrap..."
    # Show what we're executing without showing passwords
    echo "Contents of SQL script (passwords redacted):"
    cat "$TMP_SQL" | sed 's/IDENTIFIED BY .*/IDENTIFIED BY [REDACTED];/g'
    
    # Execute the SQL file with bootstrap
    mysqld --user=mysql --bootstrap < "$TMP_SQL"
    SQL_RESULT=$?
    
    if [ $SQL_RESULT -eq 0 ]; then
        echo "MariaDB database initialized successfully!"
    else
        echo "ERROR: Failed to initialize MariaDB database (exit code: $SQL_RESULT)"
        echo "Trying alternative method..."
        
        # Create another temporary SQL file with alternative syntax
        ALT_SQL=$(mktemp)
        cat > "$ALT_SQL" <<EOF
USE mysql;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER '${MYSQL_USER}'@'%';
SET PASSWORD FOR '${MYSQL_USER}'@'%' = PASSWORD('${MYSQL_PASSWORD}');
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${MYSQL_ROOT_PASSWORD}');
FLUSH PRIVILEGES;
EOF
        
        # Execute the alternative SQL
        mysqld --user=mysql --bootstrap < "$ALT_SQL"
        ALT_RESULT=$?
        
        if [ $ALT_RESULT -eq 0 ]; then
            echo "MariaDB database initialized successfully with alternative approach"
        else
            echo "ERROR: Both initialization approaches failed"
            echo "Last error output:"
            mysqld --user=mysql --bootstrap < "$ALT_SQL" 2>&1 || true
            exit 1
        fi
    fi
    
    # Cleanup
    rm -f "$TMP_SQL" "$ALT_SQL" 2>/dev/null
else
    echo "MariaDB database directory already exists, skipping initialization"
fi

echo "Starting main MariaDB process with command: $@"
exec "$@"