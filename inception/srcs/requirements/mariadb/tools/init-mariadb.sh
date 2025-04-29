#!/bin/bash

if [ ! -d "/var/lib/mysql/mysql" ]; then
	mysql_install_db --user=mysql
	mysqld --user=mysql --bootstrap << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF
	echo "MariaDB database initialized with user '${MYSQL_USER}' and database '${MYSQL_DATABASE}'"
else
	echo "MariaDB database directory already exists, skipping initialization"
fi

exec "$@"
