/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:00:05 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	cout
		<< "Animal constructor"
		<< endl;
}

Animal::Animal( Animal const &rhs )
{
	*this = rhs;
	cout
		<< "Animal copy constructor"
		<< endl;
}

Animal::~Animal()
{
	cout
		<< "Animal destructor"
		<< endl;
}

Animal	&Animal::operator=( Animal const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	Animal::makeSound( void ) const
{
	cout
		<< "?????????"
		<< endl;
}

string	Animal::getType() const
{
	return (this->_type);
}