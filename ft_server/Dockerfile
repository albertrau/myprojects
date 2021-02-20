

# OS
FROM debian:buster

#install resources
RUN	apt-get update ; apt-get upgrade ; \
	apt-get install -y nginx mariadb-server wordpress php7.3 \
	php-mysql php-fpm php-pdo php-gd php-cli php-mbstring openssl wget

#makeSSL
RUN mkdir -p /etc/nginx/ssl ; mkdir -p /var/www/fmlkshk
RUN openssl req -x509 -nodes -days 12 -subj "/C=RF/ST=Kazan/L=Kazan/O=intra42/OU=school21/CN=fmlkshk" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

#Copy nginx conf
COPY ./srcs/fornginx .

#install Php My Admin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english /var/www/fmlkshk/phpmyadmin
COPY ./srcs/forphpmyadmin /var/www/fmlkshk/phpmyadmin
RUN mv /var/www/fmlkshk/phpmyadmin/forphpmyadmin /var/www/fmlkshk/phpmyadmin/config.inc.php

# Install Wordpress
RUN mv /usr/share/wordpress /var/www/fmlkshk/wordpress
COPY ./srcs/forwordpress /var/www/fmlkshk/wordpress/
RUN mv /var/www/fmlkshk/wordpress/forwordpress /var/www/fmlkshk/wordpress/wp-config.php

# Configure Nginx
RUN mv /fornginx /etc/nginx/sites-available/default
COPY ./srcs/autoindex.sh /var/www/fmlkshk/

# When I open bash, will open this directory
WORKDIR /var/www/fmlkshk/

# Auth
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

# Open ports
EXPOSE 80 443

# Init
COPY ./srcs/init.sh /var/www
RUN chmod +x /var/www/init.sh
RUN chmod +x /var/www/fmlkshk/autoindex.sh

# start command == entry point
CMD /var/www/init.sh


