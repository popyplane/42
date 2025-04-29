FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && apt-get clean \
    && rm -rf var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld

COPY ./conf/mariadb.cnf /etc/mysql/mariadb.cnf

COPY ./tools/init-mariadb.sh /usr/local/bin
RUN chmod +x /usr/local/bin/init-mariadb.sh

EXPOSE 3306

ENTRYPOINT ["init-mariadb.sh"]
CMD ["mysqld"]