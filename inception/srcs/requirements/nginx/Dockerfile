FROM	debian:bullseye

RUN		apt-get update && \
		apt-get install -y nginx && \
		apt-get clean

COPY	./test /var/www/html

EXPOSE	80

