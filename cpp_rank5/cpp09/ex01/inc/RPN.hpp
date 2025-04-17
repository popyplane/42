/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:41:49 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:41:50 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP


# include <string>
# include <stack>
# include <limits>
# include <iostream>
# include <sstream>
# include <exception>

# define ERR_EMPTY_STACK std::string("cannot calculate due to empty stack")
# define ERR_INVALID_INPUT std::string("invalid RPN expression")
# define ERR_INVALID_OP std::string("invalid operator")
# define ERR_OVERFLOW std::string("overflow detected")
# define ERR_DIV_ZERO std::string("division by zero")

void	calculateRPN(const std::string expression);
int		getLastValue(std::stack<int> &stack);
int		calculate(int a, int b, char operand);
bool	isValidInput(std::string expression);
bool	isValidOperator(char token);

#endif