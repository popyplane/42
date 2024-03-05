/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:36:50 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/03/05 17:08:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int     main()
{
    cout << RED
        << "------ Constructing a FragTrap ------"
        << ENDCOLOR << endl;

	FragTrap fragTrapJon("Jon");
	
    cout << BLUE
        << fragTrapJon
        << ENDCOLOR << endl;

	fragTrapJon.attack("Eric");
	fragTrapJon.beRepaired(5);
	fragTrapJon.takeDamage(10);

	cout << BLUE
        << fragTrapJon
        << ENDCOLOR << endl;

	fragTrapJon.highFivesGuys();

	fragTrapJon.takeDamage(200);
	
    cout << BLUE
        << fragTrapJon
        << ENDCOLOR << endl;


    return ( 0 ); 
}