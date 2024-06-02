/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 15:32:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*********************** TESTING FUNCTIONS *******************/

void    print_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->heigh)
    {
        ft_printf(map->map[i]);
    }
}


/************************** MAIN *****************************/


int main(int ac, char **av)
{
    t_map   *map;

    if (ac == 2)
    {
        map = get_map(av[1]);
        print_map(map);
    }


    return (1);
}