/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:38:48 by codespace         #+#    #+#             */
/*   Updated: 2024/03/05 16:39:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ClapTrap.hpp"
#include <string>

using std::string;

ScavTrap::ScavTrap( string name ) : ClapTrap(name)
{
	cout << PURPLE
		<< "## ScavTrap Default constructor called"
		<< ENDCOLOR << endl;
	this->_hitPoints = 150;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	cout << PURPLE
		<< "## ScavTrap Default destructor called"
		<< ENDCOLOR << endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	cout << PURPLE
		<< "## ScavTrap copy constructor called"
		<< ENDCOLOR << endl;
	this->_hitPoints =  other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		cout << PURPLE
			<< "## ScavTrap copy assignement called"
			<< ENDCOLOR << endl;
		this->_hitPoints =  other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return ( *this );
}

void    ScavTrap::attack(const string& target)
{
	if (this->_energyPoints > 0)
	{	
		cout << YELLOW
			<< "ScavTrap " << this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!"
			<< ENDCOLOR << endl;
		this->_energyPoints--;
	}
	else
		cout << RED
			<< this->_name << " is out of energy! He can't attack anymore."
			<< ENDCOLOR << endl;
}

void    ScavTrap::guardGate( void )
{
	cout << GREEN
		<< "ScavTrap " << this->_name << " is now in Gate Keeper Mode."
		<< ENDCOLOR << endl;
}


std::ostream &operator<<(std::ostream &out, ScavTrap const & scavTrap)
{
	cout
		<< "Name: " << scavTrap.getName()
		<< " HP: " << scavTrap.getHitPoints()
		<< " EP: " << scavTrap.getEnergyPoints()
		<< " Attack Damage: " << scavTrap.getAttackDamage();
	return out;
}