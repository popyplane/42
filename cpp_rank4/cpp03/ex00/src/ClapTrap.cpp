/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:36:44 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/01 13:56:58 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap( string name )
{
    cout << "ClapTrap constructor called" << endl;
    this->_name = name;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap destructor called" << endl;
}