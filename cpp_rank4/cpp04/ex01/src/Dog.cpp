/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:16:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 18:37:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : _brain(new Brain)
{
	cout
		<< "Dog constructor"
		<< endl;
    this->_type = "Dog";
}

Dog::Dog( Dog const &rhs ) : Animal(rhs)
{
	cout
		<< "Dog copy constructor"
		<< endl;
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
}

Dog::~Dog()
{
	cout
		<< "Dog destructor"
		<< endl;
	delete _brain;
}

Dog     &Dog::operator=( Dog const &rhs )
{
    _type = rhs.getType();
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Dog::makeSound( void ) const
{
	cout
		<< "Woof !!"
		<< endl;
}
