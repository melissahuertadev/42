# FT_SERVER
> Creating a LEMP server with Docker 🐳

## Requeriments

- **Dockerfile**: should be in the root of the repo, you can not use ```docker-compose```   
- **srcs**: all the necessary files for the configuration of the server, including  the necessary files for your WordPress website.

## Learning

**What is a dockerfile?**

A Dockerfile set instructions (commands) to build images automatically.

https://docs.docker.com/get-started/overview/

https://www.youtube.com/watch?v=LQjaJINkQXY

## Solving ~

- [x] The container OS must be debian buster.
- [x] You must set up a web server with Nginx, in only one docker container.
- [x] Your web server must be able to run several services at the same time.
 The services will be a WordPress website, phpMyAdmin and MySQL.
 You will need to make sure your SQL database works with the WordPress and phpMyAdmin.
- [x] Your server should be able to use the SSL protocol.
- [x] You will have to make sure that, depending on the url, your server redirects to the
correct website.
- [ ] You will also need to make sure your server is running with an autoindex that must be able to be disabled.
