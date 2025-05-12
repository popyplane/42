#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

# Colors for better readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== MariaDB Debug Script ===${NC}"

# Clean up any existing test containers/volumes
echo -e "${YELLOW}Cleaning up existing resources...${NC}"
docker stop mariadb-debug-container 2>/dev/null || true
docker rm mariadb-debug-container 2>/dev/null || true
docker volume rm mariadb_debug_vol 2>/dev/null || true
docker rmi mariadb-debug -f 2>/dev/null || true

# Build the MariaDB debug image directly using the existing files
echo -e "${YELLOW}Building MariaDB debug image...${NC}"
docker build -t mariadb-debug srcs/requirements/mariadb

# Create volume for MariaDB data
echo -e "${YELLOW}Creating volume for MariaDB data...${NC}"
docker volume create mariadb_debug_vol

# Run the container with debug flags
echo -e "${GREEN}Starting MariaDB container with debug settings...${NC}"
echo -e "${YELLOW}You'll see debug output. When the container is ready, try connecting to it.${NC}"

# Run with bash in interactive mode first, to verify the script permissions
echo -e "${YELLOW}Verifying script permissions...${NC}"
docker run --rm --name mariadb-perm-check \
    -v "$(pwd)/srcs/requirements/mariadb/tools/init-mariadb.sh:/init-mariadb.sh:ro" \
    debian:bullseye bash -c "ls -la /init-mariadb.sh && echo 'Script permissions checked'"

# Run the container with direct volume mounting of the init script to add debugging capability
docker run --name mariadb-debug-container \
    --env-file srcs/.env \
    -p 3306:3306 \
    --mount type=volume,source=mariadb_debug_vol,target=/var/lib/mysql \
    mariadb-debug

echo -e "${YELLOW}Container exited. Checking container status:${NC}"
docker inspect -f '{{.State.Status}}' mariadb-debug-container || echo "Container not found"
echo -e "${YELLOW}Container exit code:${NC}"
docker inspect -f '{{.State.ExitCode}}' mariadb-debug-container || echo "Container not found"

echo -e "${YELLOW}=== Test if MySQL is working properly ===${NC}"
echo -e "${GREEN}Restarting container to test connection...${NC}"

docker start mariadb-debug-container || echo -e "${RED}Failed to restart container${NC}"
sleep 5  # Give MySQL time to start

# Test MySQL connection
echo -e "${YELLOW}Testing MySQL connection...${NC}"
docker exec -i mariadb-debug-container mysql -u wpuser -p"wppassword" -e "SHOW DATABASES;" 2>/dev/null || echo -e "${RED}MySQL connection failed${NC}"

# Check logs
echo -e "${YELLOW}Container logs:${NC}"
docker logs mariadb-debug-container

echo -e "${YELLOW}=== Debug Complete ===${NC}"
echo -e "${GREEN}If everything worked, you can now use these commands:${NC}"
echo "docker exec -it mariadb-debug-container mysql -u root -prootpassword"  # To connect as root
echo "docker exec -it mariadb-debug-container mysql -u wpuser -pwppassword" # To connect as wpuser

# Provide cleanup command
echo -e "${YELLOW}When done, clean up with:${NC}"
echo "docker stop mariadb-debug-container && docker rm mariadb-debug-container && docker volume rm mariadb_debug_vol && docker rmi mariadb-debug"