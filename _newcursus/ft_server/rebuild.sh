docker build -t ft_server .
docker run --name ft_server -it -p80:80 -p443:443 ft_server

#docker build .
#docker images
#docker run -p 81:80 --name [name_server][image id]
#kill zombies docker rm $(docker ps -qa)