#!/bin/bash
set -e  # Exit immediately if a command exits with non-zero status

# Colors for better readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=== MariaDB Container Debug Script ===${NC}"

# Clean up any existing test containers/volumes
echo -e "${YELLOW}Cleaning up existing resources...${NC}"
docker stop mariadb-debug-container 2>/dev/null || true
docker rm mariadb-debug-container 2>/dev/null || true
docker volume rm mariadb_debug_vol 2>/dev/null || true
docker rmi mariadb-debug -f 2>/dev/null || true

# Build the MariaDB image
echo -e "${YELLOW}Building MariaDB debug image...${NC}"
docker build -t mariadb-debug srcs/requirements/mariadb

# Create a volume for MariaDB data
echo -e "${YELLOW}Creating volume for MariaDB data...${NC}"
docker volume create mariadb_debug_vol

# Print environment variables being used (without showing passwords)
echo -e "${YELLOW}Environment variables that will be used:${NC}"
grep -v PASSWORD srcs/.env || echo "No .env file found!"

# Run the container without detaching to see all logs
echo -e "${GREEN}Starting MariaDB container in foreground mode to view logs...${NC}"
echo -e "${YELLOW}Press Ctrl+C after observing the logs to stop the container${NC}"
echo 

# Start the container without the --rm flag so we can inspect it after exit
docker run --name mariadb-debug-container \
    --env-file srcs/.env \
    -p 3306:3306 \
    --mount type=volume,source=mariadb_debug_vol,target=/var/lib/mysql \
    mariadb-debug

# The above command will show all logs. After Ctrl+C, we'll run some diagnostics

echo -e "${YELLOW}=== Post-Run Diagnostics ===${NC}"
echo -e "${YELLOW}Container status:${NC}"
docker inspect -f '{{.State.Status}}' mariadb-debug-container 2>/dev/null || echo "Container no longer exists"

echo -e "${YELLOW}Container exit code:${NC}"
docker inspect -f '{{.State.ExitCode}}' mariadb-debug-container 2>/dev/null || echo "Cannot get exit code"

echo -e "${YELLOW}Last 20 lines of logs:${NC}"
docker logs mariadb-debug-container 2>&1 | tail -20 || echo "No logs available"

echo -e "${YELLOW}Checking volume contents:${NC}"
docker run --rm -v mariadb_debug_vol:/data alpine ls -la /data || echo "Could not check volume"

echo -e "${RED}Cleanup: To remove all debugging resources, run:${NC}"
echo "docker stop mariadb-debug-container; docker rm mariadb-debug-container; docker volume rm mariadb_debug_vol; docker rmi mariadb-debug"