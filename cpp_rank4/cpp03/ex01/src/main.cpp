/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:36:50 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/01 13:36:57 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int     main()
{
    ClapTrap clapTrap_belly("Belly");
	cout << BLUE
        << clapTrap_belly
        << ENDCOLOR << endl;

	cout << RED
        << "*------ Constructing a ScavTrap ------*"
        << ENDCOLOR << endl;

	ScavTrap scavTrap_jean("Jean");
	cout << BLUE
        << scavTrap_jean
        << ENDCOLOR << endl;;

	scavTrap_jean.attack("Eric");
	scavTrap_jean.beRepaired(20);
	scavTrap_jean.takeDamage(8);

	cout << BLUE
        << scavTrap_jean
        << ENDCOLOR << endl;
	
    scavTrap_jean.guardGate();
	scavTrap_jean.takeDamage(200);
	
    cout << BLUE
        << scavTrap_jean
        << ENDCOLOR << endl;

	cout << RED
        << "*------ Constructing a ScavTrap from another Scavtrap ------*"
        << ENDCOLOR << endl;
	
    ScavTrap scavTrapCopy(scavTrap_jean);
	
    cout << BLUE
        << scavTrapCopy
        << ENDCOLOR << endl;

	cout << RED
        << "*------ Create a reference to ScavTrap ------*"
        << ENDCOLOR << endl;
	
    ClapTrap &clapTrapRef = scavTrap_jean;
	clapTrapRef.beRepaired(10);

	cout << RED
        << "*------ Destructing created objects ------*"
        << ENDCOLOR << endl;


    return ( 0 ); 
}