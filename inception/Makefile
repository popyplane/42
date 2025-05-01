all:
	docker-compose -f /srcs/docker-compose.yml up -d --build

mariadb-test-clean:
	docker stop mariadb-test-container 2>/dev/null || true
	docker rm mariadb-test-container 2>/dev/null || true
	docker volume rm mariadb_test_vol 2>/dev/null || true
	docker rmi mariadb-test -f 2>/dev/null || true

mariadb-test: mariadb-test-clean
	docker build -t mariadb-test srcs/requirements/mariadb
	docker volume create mariadb_test_vol
	docker run --name mariadb-test-container --rm -d \
		--env-file srcs/.env \
		-p 3306:3306 \
		--mount type=volume,source=mariadb_test_vol,target=/var/lib/mysql \
		mariadb-test
	@echo "MariaDB container is running."
	@echo "To check initialization logs: docker logs mariadb-test-container"
	@echo "To test connection: docker exec -it mariadb-test-container mysql -u root -p"
	@echo "When finished testing, run: make mariadb-test-clean"

stop:
	docker-compose -f srcs/docker-compose.yml down

clean: stop mariadb-test-clean
	docker system prune -a

fclean: clean
	docker volume prune -f

re: fclean all

.phony: all mariadb-test-clean mariadb-test stop clean fclean re