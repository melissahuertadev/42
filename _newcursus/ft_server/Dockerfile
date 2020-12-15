# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 19:26:14 by mhuerta           #+#    #+#              #
#    Updated: 2020/12/15 00:21:13 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

MAINTAINER mhuerta <mhuerta@student.42.fr>

# ----UPDATE PKGS & INSTALLATION----
#nginx
RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get -y install wget nginx openssl
#php
RUN apt-get install -y php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common \
     php7.3-json php7.3-opcache php7.3-readline php-mbstring php-zip php-gd
#php extensions for wordpress
RUN apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
#mysql
RUN apt-get install -y mariadb-server mariadb-client
#cleaning after installation
RUN apt-get clean && rm -rf /var/lib/apt/lists/


# ----CONFIG----
#nginx
COPY srcs/nginx/localhost /etc/nginx/sites-available/localhost
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
COPY srcs/nginx/index.html ./
COPY srcs/nginx/style.css  ./

#ssl
CMD cd /etc/ssl/certs
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
     -keyout /etc/ssl/certs/localhost.key \
     -out /etc/ssl/certs/localhost.crt \
     -subj "/C=PE/ST=Lima/L=Lima/O=TheCodeLoops/OU=IT/CN=localhost"
RUN cp /etc/nginx/sites-available/localhost /etc/nginx/sites-available/localhost.bak
RUN nginx -t

#mysql
COPY srcs/mysql/db.sh ./

#php
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
COPY srcs/php/config.inc.php ./

#wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar xvf latest.tar.gz
COPY srcs/wordpress/wp-config.php ./

EXPOSE 80 443

COPY srcs/run.sh ./

#running in the container
CMD bash /run.sh