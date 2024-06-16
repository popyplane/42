/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/16 17:41:49 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// /*********************** TESTING FUNCTIONS *******************/

// void    print_map(t_map *map)
// {
//     int i;

//     i = 0;
//     while (i < map->heigh)
//     {
//         ft_printf(map->map[i]);
//         i++;
//     }
//     ft_printf("\n");
// }

// void    print_texture(t_texture *texture)
// {
//     ft_printf("NO = %s", texture->north_wall);
//     ft_printf("SO = %s", texture->south_wall);
//     ft_printf("EA = %s", texture->east_wall);
//     ft_printf("WE = %s", texture->west_wall);
//     ft_printf("C = %s", texture->ceiling);
//     ft_printf("F = %s", texture->floor);
// }


// /************************** MAIN *****************************/


// int main(int ac, char **av)
// {
//     t_map   map;

//     if (ac == 2)
//     {
//         map = *(get_map(av[1]));
//         print_map(&map);
//         print_texture(map.texture);
//     }
//     return (1);
// }

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

int	main(void)
{
    t_mlx	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }

    /* Setup hooks */ 
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}