/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:42:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:42:05 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C>
void    mergeInsertionSort(C &arr)
{
	if (arr.size() < 2)
		return;

	C   sorted;
	C   remaining;

	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
		sorted.push_back(arr[i]);
		remaining.push_back(arr[i + 1]);
	}
	if (arr.size() % 2 != 0)
		remaining.push_back(arr.back());
	mergeInsertionSort(sorted);
	for (size_t i = 0; i < remaining.size(); i++)
		binaryInsert(remaining[i], sorted);
	arr = sorted;
}

template <typename C>
void    binaryInsert(int value, C &sorted)
{
	typename C::iterator    it;
	
	it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

template <typename C>
void	printContainer(std::string msg, C c)
{
	std::cout << msg;
	for (typename C::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename C>
double	getSortTime(C &arr)
{
	clock_t	start = clock();
	mergeInsertionSort(arr);
	clock_t end = clock();
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}