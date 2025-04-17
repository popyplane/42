/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:41:56 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:41:57 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

void calculateRPN(const std::string expression)
{
	if (!isValidInput(expression))
		throw (std::runtime_error(ERR_INVALID_INPUT));

	std::stringstream	ss(expression);
	std::stack<int>		stack;

	for (std::string token; std::getline(ss, token, ' ');) {
		if (token.empty() || token.size() != 1)
			throw (std::runtime_error(ERR_INVALID_INPUT));
		if (isdigit(token[0])) {
			stack.push(token[0] - '0');
			continue;
		}
		int	b = getLastValue(stack);
		int	a = getLastValue(stack);
		stack.push(calculate(a, b, token[0]));
	}
	std::cout << stack.top() << std::endl;
}

int	getLastValue(std::stack<int> &stack)
{
	if (stack.empty())
		throw (std::runtime_error(ERR_EMPTY_STACK));
	
	int	rval = stack.top();
	stack.pop();
	return (rval);
}

int	calculate(int a, int b, char operand)
{
	if (!isValidOperator(operand))
		throw (std::runtime_error(ERR_INVALID_INPUT));

	long long	result;
	switch (operand) {
		case ('+') :
			result = static_cast<long long>(a) + b;
			break;
		case ('-') :
			result = static_cast<long long>(a) - b;
			break;
		case ('*') :
			if ((a > 0 && b > 0 && std::numeric_limits<int>::max() / b < a) ||
				(a > 0 && b < 0 && std::numeric_limits<int>::min() / a > b) ||
				(a < 0 && b > 0 && std::numeric_limits<int>::min() / b > a) ||
				(a < 0 && b < 0 && std::numeric_limits<int>::max() / a > b))
				throw std::overflow_error(ERR_OVERFLOW);    		
			result = static_cast<long long>(a) * b;
			break;
		case ('/') :
			if (b == 0)
				throw std::runtime_error(ERR_DIV_ZERO);
			result = static_cast<long long>(a) / b;
			break;
		default :
		  throw std::runtime_error(ERR_INVALID_OP);
	}
	if (result > std::numeric_limits<int>::max() ||
		result < std::numeric_limits<int>::min())
		throw (std::overflow_error(ERR_OVERFLOW));
	return (static_cast<int>(result));
}

bool	isValidInput(std::string expression)
{
	if (expression.empty())
		return (false);

	bool	hasValue = false;
	for (size_t i = 0; i < expression.size(); i++) {
		if (expression[i] == ' ')
			continue;
		if (!isdigit(expression[i]) && !isValidOperator(expression[i]))
			return (false);
		if (i != expression.size() - 1 && expression[i + 1] != ' ')
			return (false);
		if (!hasValue)
			hasValue = true;
	}
	return (hasValue);
}

bool	isValidOperator(char token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}