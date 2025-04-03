#include "../inc/PmergeMe.hpp"

void    parseInput(int argc, char **argv, std::vector<int> &vec)
{
    vec.reserve(argc - 1);
    for (int i = 1; i < argc; i++) {
        char    *endptr;
        errno = 0;
        long    num = std::strtol(argv[i], &endptr, 10);
        if (errno != 0 || num < 0 || num > std::numeric_limits<int>::max() || *endptr != '\0') {
            std::ostringstream  oss;
            oss << "Error: Invalid input: \"" << argv[i] << "\"";
            throw (std::runtime_error(oss.str()));
        }
        vec.push_back(static_cast<int>(num));
    }
}

