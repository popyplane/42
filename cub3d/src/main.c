/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/16 09:31:20 by codespace        ###   ########.fr       */
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

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}