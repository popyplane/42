/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:37:02 by codespace         #+#    #+#             */
/*   Updated: 2024/03/06 17:54:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
	cout
		<< "Brain constructor"
		<< endl;
    _setIdeas();
}

Brain::Brain( Brain const &rhs )
{
	cout
		<< "Brain copy constructor"
		<< endl;
	for(int i = 0; i < 100; ++i)
		_ideas[i] = rhs._ideas[i];
}

Brain::~Brain()
{
	cout
		<< "Brain destructor"
		<< endl;
}

Brain     &Brain::operator=( Brain const &rhs )
{
    if (this != &rhs)
        for (int i = 0; i < 100; i++)
            _ideas[i] = rhs._ideas[i];
	return (*this);
}

void    Brain::_setIdeas()
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = "No idea ...";
}