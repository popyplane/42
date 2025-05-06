FROM debian:bullseye

# Install packages and clean up in one layer to reduce image size
RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    procps \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Clear existing MySQL data
RUN rm -rf /var/lib/mysql/*

# Set up MySQL directories with proper permissions
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld

# Create log directory with proper permissions
RUN mkdir -p /var/log/mysql \
    && chown -R mysql:mysql /var/log/mysql

# Copy configuration file
COPY ./conf/mariadb.cnf /etc/mysql/mariadb.cnf

# Copy initialization script
COPY ./tools/init-mariadb.sh /usr/local/bin/

# Make sure the script has Unix line endings and is executable
RUN sed -i 's/\r$//' /usr/local/bin/init-mariadb.sh \
    && chmod +x /usr/local/bin/init-mariadb.sh

# Make sure the data directory has proper ownership
RUN chown -R mysql:mysql /var/lib/mysql

# Verify the script is executable and displays properly
RUN ls -la /usr/local/bin/init-mariadb.sh && \
    head -n 5 /usr/local/bin/init-mariadb.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/init-mariadb.sh"]
CMD ["mysqld"]