/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:12:29 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:17:48 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat()
{
	cout << YELLOW
		<< "Cat constructor"
		<< ENDCOLOR << endl;
    this->_type = "Cat";
}

Cat::Cat( Cat const &rhs )
{
	cout << YELLOW
		<< "Cat copy constructor"
		<< ENDCOLOR << endl;
	*this = rhs;
}

Cat::~Cat()
{
	cout << YELLOW
		<< "Cat destructor"
		<< ENDCOLOR << endl;
}

Cat     &Cat::operator=( Cat const &rhs )
{
    this->_type = rhs.getType();
	return (*this);
}

void	Cat::makeSound( void ) const
{
	cout << YELLOW
		<< "Meow !!"
		<< ENDCOLOR << endl;
}
