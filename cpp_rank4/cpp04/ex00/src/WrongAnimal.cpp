/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:23:31 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:05:31 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout
		<< "WrongAnimal constructor"
		<< endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &rhs )
{
	*this = rhs;
	cout
		<< "WrongAnimal copy constructor"
		<< endl;

}

WrongAnimal::~WrongAnimal()
{
	cout
		<< "WrongAnimal destructor"
		<< endl;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs )
{
    this->_type = rhs.getType();
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	cout
		<< "Wrong ?????????"
		<< endl;
}

string	WrongAnimal::getType() const
{
	return (this->_type);
}