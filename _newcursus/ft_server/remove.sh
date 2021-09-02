docker rm -f  ft_server
#kill zombies
docker rm $(docker ps -qa)
docker system prune