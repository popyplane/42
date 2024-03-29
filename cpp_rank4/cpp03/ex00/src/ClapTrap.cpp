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
	cout
		<< "## ClapTrap constructor called to create " << name
		<< endl;
	this->_name = name;

}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	cout
		<< "## ClapTrap copy constructor called to create a copy of " << src._name
		<< endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	cout
		<< "## ClapTrap destructor called to delete "<< this->_name
		<< endl;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const &rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._energyPoints;
	}
	return (*this);
}

void    ClapTrap::attack(const string& target)
{
	if (this->_energyPoints > 0)
	{	
		cout << YELLOW
			<< this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!"
			<< ENDCOLOR << endl;
		this->_energyPoints--;
	}
	else
		cout << RED
			<< this->_name << " is out of energy! He can't attack anymore."
			<< ENDCOLOR << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	cout << YELLOW
		<< this->_name << " takes " << amount << " damage!"
		<< ENDCOLOR << endl;

	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		cout << RED
			<< this->_name << " has no more hit points!"
			<< endl
			<< this->_name << " is defeated!"
			<< ENDCOLOR << endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{	
		cout << GREEN
			<< this->_name << " heals by " << amount << " hit points."
			<< ENDCOLOR << endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		cout << RED
			<< this->_name << " is out of energy! He can't heal anymore."
			<< ENDCOLOR << endl; 
}