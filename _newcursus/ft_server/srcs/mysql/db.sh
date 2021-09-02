# Configure a wordpress database
echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpress.* TO 'meli'@'localhost' IDENTIFIED BY 'ssa';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root