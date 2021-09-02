#nginx files
mkdir -p /var/www/localhost/html/
chown -R www-data:www-data /var/www/localhost
mv ./index.html /var/www/localhost/html/
mv ./style.css /var/www/localhost/html/

#MYSQL
service mysql start
bash /db.sh

#php files
mv phpMyAdmin-4.9.0.1-all-languages var/www/localhost/phpmyadmin
mv ./config.inc.php /var/www/localhost/phpmyadmin
chmod 660 /var/www/localhost/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/localhost/phpmyadmin

#wordpress
mkdir var/www/localhost/wordpress
cp -a wordpress/. /var/www/localhost/wordpress
mv ./wp-config.php /var/www/localhost/wordpress

#starting services
service nginx start
service mysql start
service php7.3-fpm start

sleep infinity