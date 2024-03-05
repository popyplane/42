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
    ClapTrap    bob;
    ClapTrap    bob2 = bob;
    ClapTrap    tom( "Tom" );

    tom.attack( "bob" );
    tom.takeDamage( 10 );
    tom.beRepaired( 10 );
    tom.takeDamage( 2 );
    tom.takeDamage( 2 );
    tom.takeDamage( 2 );
    tom.takeDamage( 2 );
    tom.takeDamage( 2 );
    tom.beRepaired( 100 );
    tom.attack( "a dragon" );
    tom.attack( "nobody" );
    tom.attack( "himself!?" );
    tom.attack( "chickens" );
    tom.attack( "trolls" );
    tom.attack( "DARK VADOR" );
    tom.attack( "the final boss" );
    tom.takeDamage( 50 );
    tom.takeDamage( 10 );
    tom.beRepaired( 20 );
    tom.attack( "ourson" );

    bob.attack( "Tom" );
    tom.takeDamage( 0 );

    return ( 0 ); 
}