/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:41:53 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:41:54 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"input\"\n";
		return 1;
	}
	try {
		calculateRPN(argv[1]);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << "\n";
		return 1;
	}
	return 0;
}