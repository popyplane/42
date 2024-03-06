/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:16:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 22:18:31 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog()
{
	cout << YELLOW
		<< "Dog constructor"
		<< ENDCOLOR << endl;
    this->_type = "Dog";
}

Dog::Dog( Dog const &rhs )
{
	cout << YELLOW
		<< "Dog copy constructor"
		<< ENDCOLOR << endl;
	*this = rhs;

}

Dog::~Dog()
{
	cout << YELLOW
		<< "Dog destructor"
		<< ENDCOLOR << endl;
}

Dog	    &Dog::operator=( Dog const &rhs )
{
	this->_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound( void ) const
{
	cout << YELLOW
		<< "Woof !!"
		<< ENDCOLOR << endl;
}
