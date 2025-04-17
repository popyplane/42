/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:42:11 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:42:12 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

