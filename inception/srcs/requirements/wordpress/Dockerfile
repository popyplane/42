FROM    debian:bullseye

RUN apt-get update && apt-get install -y \
	wget \
	php \
	php-cgi \
	php-mysql \
	php-fpm \
	php-pdo \
	php-gd \
	php-cli \
	php-mbstring \
	&& rm -rf var/lib/apt/lists/*