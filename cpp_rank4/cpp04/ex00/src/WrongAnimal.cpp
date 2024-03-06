/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:23:31 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:19:24 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout << RED
		<< "WrongAnimal constructor"
		<< ENDCOLOR << endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &rhs )
{
	*this = rhs;
	cout << RED
		<< "WrongAnimal copy constructor"
		<< ENDCOLOR << endl;

}

WrongAnimal::~WrongAnimal()
{
	cout << RED
		<< "WrongAnimal destructor"
		<< ENDCOLOR << endl;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs )
{
    this->_type = rhs.getType();
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	cout << RED
		<< "Wrong ?????????"
		<< ENDCOLOR << endl;
}

string	WrongAnimal::getType() const
{
	return (this->_type);
}