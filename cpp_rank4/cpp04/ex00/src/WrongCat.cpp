/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:24:21 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:26 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	cout
		<< "WrongCat constructor"
		<< endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &rhs )
{
	cout
		<< "WrongCat copy constructor"
		<< endl;
	*this = rhs;
}

WrongCat::~WrongCat()
{
	cout
		<< "WrongCat destructor"
		<< endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	cout
		<< "Wrong Meow !!"
		<< endl;
}
