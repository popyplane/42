/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:12:29 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/06 18:35:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : _brain(new Brain)
{
	cout
		<< "Cat constructor"
		<< endl;
    this->_type = "Cat";
}

Cat::Cat( Cat const &rhs ) : Animal(rhs)
{
	cout
		<< "Cat copy constructor"
		<< endl;
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
}

Cat::~Cat()
{
	cout
		<< "Cat destructor"
		<< endl;
	delete _brain;
}

Cat     &Cat::operator=( Cat const &rhs )
{
    _type = rhs.getType();
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Cat::makeSound( void ) const
{
	cout
		<< "Meow !!"
		<< endl;
}
