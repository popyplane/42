/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:24:21 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:20:04 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	cout << YELLOW
		<< "WrongCat constructor"
		<< ENDCOLOR << endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &rhs )
{
	cout << YELLOW
		<< "WrongCat copy constructor"
		<< ENDCOLOR << endl;
	*this = rhs;
}

WrongCat::~WrongCat()
{
	cout << YELLOW
		<< "WrongCat destructor"
		<< ENDCOLOR << endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	cout << YELLOW
		<< "Wrong Meow !!"
		<< ENDCOLOR << endl;
}
