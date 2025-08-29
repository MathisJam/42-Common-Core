FROM debian:bullseye

RUN apt update -y && apt upgrade -y && \
    apt-get install -y wget php php-fpm php-mysql mariadb-client && \
    wget https://fr.wordpress.org/wordpress-6.8.2-fr_FR.tar.gz -P /var/www && \
    cd /var/www && tar -xzf wordpress-6.8.2-fr_FR.tar.gz && rm wordpress-6.8.2-fr_FR.tar.gz && \
	mkdir -p /run/php

RUN chown -R root:root /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar


RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf	/etc/php/7.4/fpm/pool.d/www.conf

COPY conf/run.sh /tmp/run.sh
RUN chmod +x /tmp/run.sh


ENTRYPOINT [ "sh", "/tmp/run.sh" ]
