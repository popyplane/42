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

# Only initialize if this is the first start
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    
    # Print directory structure for debugging
    echo "Directory structure before initialization:"
    ls -la /var/lib/mysql/
    
    # Initialize the database
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
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
    
    # Cleanup
    rm -f "$TMP_SQL"
    
    echo "MariaDB database initialized successfully!"
fi

echo "Starting MariaDB server..."

exec "$@"