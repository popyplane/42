/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:15:50 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	cout << RED
		<< "Animal constructor"
		<< ENDCOLOR << endl;
}

Animal::Animal( Animal const &rhs )
{
	*this = rhs;
	cout << RED
		<< "Animal copy constructor"
		<< ENDCOLOR << endl;
}

Animal::~Animal()
{
	cout << RED
		<< "Animal destructor"
		<< ENDCOLOR << endl;
}

Animal	&Animal::operator=( Animal const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	Animal::makeSound( void ) const
{
	cout << RED
		<< "?????????"
		<< ENDCOLOR << endl;
}

string	Animal::getType() const
{
	return (this->_type);
}