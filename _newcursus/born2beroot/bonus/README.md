## Bonus
> The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning.  If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.


### Partitions

- [x] Set up partitions correctly so you get a structure similar to the one below:

partition | size | use as
--- | --- | ---
root | 2G | Ext4 (mount: /)
swap | 1G | swap area
home | 1G | Ext4 (mount: /home)
var | 1G | Ext4 (mount: /var)
srv | 1G | Ext4 (mount: /srv)
tmp | 1G | Ext4 (mount: /tmp)
var-log | all disk space that left | Ext4 (manually mount: /var/log)

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/lsblk_results.png" alt="lsblk results" width="560"/><br/>


### Services

[+ Installation steps](https://www.osradar.com/install-wordpress-with-lighttpd-debian-10/)

Note: to check if a package is well installed, use this command:
```$ dpkg -l | grep <package_name>```


- [x] Set up a functional WordPress website with the following services: lighttpd, Mari- aDB, and PHP.

- Lighttpd and remember to allow ufw on port 80:

```
$ sudo apt install lighttpd
$ sudo ufw allow 80
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/img/encr-volumes-1.png" alt="encryption volumes" width="560"/>    <img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/bonus/img/lighttpd.png" alt="lsblk results" width="560"/><br/>

[+ Mora about lighttpd](https://www.osradar.com/install-lighttpd-debian-10/)



- MariaDB:

```
$ sudo apt-get install mariadb-server mariadb-client -y
$ sudo mysql_secure_installation
```

> Answer all the questions as shown below:
```
Change the root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```

Access to ```mariadb```:

```
$ sudo mariadb
> CREATE DATABASE wordpress;
> GRANT ALL PRIVILEGES on wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'wordpress_pss123';
> FLUSH PRIVILEGES;
> EXIT;
```

<img src="https://github.com/melissahuerta/42/blob/dev/born2reboot/_newcursus/born2beroot/bonus/img/mariadb.png" alt="maria db" width="560"/>

- PHP:

```apt-get install php php-cgi php-fpm php-mysql -y```


