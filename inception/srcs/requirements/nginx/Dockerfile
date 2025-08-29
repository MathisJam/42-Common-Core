FROM debian:bullseye

RUN apt update && apt upgrade && apt install nginx -y && apt install curl -y \
	&& apt install vim -y && mkdir -p /etc/nginx/ssl && apt install openssl -y \
	&& openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=mjameau.42.fr/UID=mjameau" \
	&& mkdir -p /var/run/nginx && chmod 755 /var/www/html && chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
