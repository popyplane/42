/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/06/21 15:03:21 by baptistevie      ###   ########.fr       */
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

#define MLX_ERROR 1

void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
        {
            img_pix_put(img, j++, i, color);
        }
        ++i;
    }
}

int	main(int ac, char **av)
{
    t_game	*data;

    data = init_game();
    if (ac != 2)
        return (0);

    data->mlx->mlx_ptr = mlx_init();
    if (data->mlx->mlx_ptr == NULL)
        return (MLX_ERROR);
    data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
    if (data->mlx->win_ptr == NULL)
    {
        free(data->mlx->win_ptr);
        return (MLX_ERROR);
    }

    data->map = get_map(av[1]);
    data->img->mlx_img = mlx_new_image(data->mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);

    /* Setup hooks */ 
    mlx_loop_hook(data->mlx->mlx_ptr, &render_2d, &data);
    mlx_hook(data->mlx->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */
    mlx_hook(data->mlx->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

    mlx_loop(data->mlx->mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data->mlx->mlx_ptr);
    free(data->mlx->mlx_ptr);

    return (1);
}