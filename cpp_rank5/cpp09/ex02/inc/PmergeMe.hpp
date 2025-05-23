/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:42:01 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:42:02 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cerrno>
# include <cstdlib>
# include <deque>
# include <vector>
# include <iostream>
# include <sstream>
# include <ctime>
# include <limits>

template <typename C>
void    mergeInsertionSort(C &arr);
template <typename C>
void    binaryInsert(int value, C &sorted);
template <typename C>
void    printContainer(std::string msg, C c);
template <typename C>
double  getSortTime(C &arr);

void    parseInput(int argc, char **argv, std::vector<int> &vec);

# include "PmergeMe.tpp"


#endif