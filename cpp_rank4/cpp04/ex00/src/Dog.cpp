/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:16:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 16:04:49 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
	cout
		<< "Dog constructor"
		<< endl;
    this->_type = "Dog";
}

Dog::Dog( Dog const &rhs )
{
	cout
		<< "Dog copy constructor"
		<< endl;
	*this = rhs;

}

Dog::~Dog()
{
	cout
		<< "Dog destructor"
		<< endl;
}

Dog	    &Dog::operator=( Dog const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound( void ) const
{
	cout
		<< "Woof !!"
		<< endl;
}
