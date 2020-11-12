# FT_SERVER
> 

## Requeriments

- **Dockerfile**: should be in the root of the repo, you can not use ```docker-compose```   
- **srcs**: all the necessary files for the configuration of the server, including  the necessary files for your WordPress website.


- [ ] Set up a web server with Nginx, in only one docker container.
- [ ] The container OS must be debian buster.
- [ ] The web server must be able to run several services at the same time.
- [ ] The services will be a WordPress website, phpMyAdmin and MySQL.
- [ ] You will need to make sure your SQL database works with the WordPress and phpMyAdmin.
- [ ] The server should be able to use the SSL protocol.
- [ ] Make sure that, depending on the url, the server redirects to the
correct website.
- [ ] Make sure your server is running with an autoindex that must be able to be disabled.