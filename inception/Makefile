NAME = inception

COMPOSE_F = ./srcs/docker-compose.yml

all: up

up :
	docker compose  -f ${COMPOSE_F} up -d --build

down:
	docker compose -f ${COMPOSE_F} down

re : clean up

clean:
	docker compose -f ${COMPOSE_F} down -v --rmi all --remove-orphans

logs:
	docker compose ${COMPOSE_F} logs

.PHONY : up down clean re logs all
