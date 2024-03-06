/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:00:05 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal()
{
	cout << CYAN
		<< "AAnimal constructor"
		<< ENDCOLOR << endl;
}

AAnimal::AAnimal( AAnimal const &rhs )
{
	*this = rhs;
	cout << CYAN
		<< "AAnimal copy constructor"
		<< ENDCOLOR << endl;
}

AAnimal::~AAnimal()
{
	cout << CYAN
		<< "AAnimal destructor"
		<< ENDCOLOR << endl;
}

AAnimal	&AAnimal::operator=( AAnimal const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	AAnimal::makeSound( void ) const
{
	cout << CYAN
		<< "?????????"
		<< ENDCOLOR << endl;
}

string	AAnimal::getType() const
{
	return (this->_type);
}