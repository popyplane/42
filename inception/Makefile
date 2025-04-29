all:
	docker-compose -f /srcs/docker-compose.yml up -d --build

mariadb-test:
	docker build -t mariadb-test srcs/requirements/mariadb
	docker run --name mariadb-test-container --rm -d \
		--env-file srcs/.env \
		-p 3306:3306 \
		mariadb-test
	@echo "MariaDB container is running. To test connection:"
	@echo "docker exec -it mariadb-test-container mysql -u root -p"

stop:
	docker-compose -f srcs/docker-compose.yml down

clean: stop
	docker system prune -a

fclean: clean
	docker volume prune -f

re: fclean all
