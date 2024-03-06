/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:12:29 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:04:45 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
	cout
		<< "Cat constructor"
		<< endl;
    this->_type = "Cat";
}

Cat::Cat( Cat const &rhs )
{
	cout
		<< "Cat copy constructor"
		<< endl;
	*this = rhs;
}

Cat::~Cat()
{
	cout
		<< "Cat destructor"
		<< endl;
}

Cat     &Cat::operator=( Cat const &rhs )
{
    this->_type = rhs.getType();
	return (*this);
}

void	Cat::makeSound( void ) const
{
	cout
		<< "Meow !!"
		<< endl;
}
