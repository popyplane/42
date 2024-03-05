/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:37:32 by codespace         #+#    #+#             */
/*   Updated: 2024/03/05 17:07:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include <string>

using std::string;

FragTrap::FragTrap( string name ) : ClapTrap(name)
{
	cout << PURPLE
		<< "## FragTrap Default constructor called"
		<< ENDCOLOR << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	cout << PURPLE
		<< "## FragTrap Default destructor called"
		<< ENDCOLOR << endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	cout << PURPLE
		<< "## FragTrap copy constructor called"
		<< ENDCOLOR << endl;
	this->_hitPoints =  other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		cout << PURPLE
			<< "## FragTrap copy assignement called"
			<< ENDCOLOR << endl;
		this->_hitPoints =  other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return ( *this );
}

void    FragTrap::highFivesGuys( void )
{
	cout << GREEN
		<< "   _.-._" << endl
		<< "  | | | |_ " << endl
		<< "  | | | | | " << endl
		<< "  | | | | | " << endl
		<< "_ |  '-._ | " << endl
		<< "\\`\\`-.'-._; " << endl
		<< " \\    '   | " << endl
		<< "  \\  .`  / " << endl
		<< "   |    | "  << endl
		<< ENDCOLOR << endl;
}

std::ostream &operator<<(std::ostream &out, FragTrap const & FragTrap)
{
	cout
		<< "Name: " << FragTrap.getName()
		<< " HP: " << FragTrap.getHitPoints()
		<< " EP: " << FragTrap.getEnergyPoints()
		<< " Attack Damage: " << FragTrap.getAttackDamage();
	return out;
}