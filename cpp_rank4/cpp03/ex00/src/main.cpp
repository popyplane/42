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
    ClapTrap    tom("Tom");

    tom.attack("bob");
}