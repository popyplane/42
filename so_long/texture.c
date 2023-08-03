/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:29:25 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:42:41 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "texture.h"
#include "error.h"
#include "structs.h"

t_bool	load_textures(t_mlx *mlx)
{
	char	*texture_map[5];
	int		size;
	int		i;

	texture_map[0] = FLOOR_PATH;
	texture_map[1] = WALL_PATH;
	texture_map[2] = COLLECTIBLE_PATH;
	texture_map[3] = PLAYER_PATH;
	texture_map[4] = EXIT_PATH;
	i = -1;
	while (++i < 5)
	{
		mlx->textures[i] = mlx_xpm_file_to_image(
				mlx->mlx_ptr, texture_map[i], &size, &size);
		if (!mlx->textures[i])
		{
			while (--i >= 0)
				mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i]);
			return (false);
		}
	}
	return (true);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error(MALLOC_FAILURE);
	data->collectible = 0;
	data->exit = 0;
	data->start = 0;
	return (data);
}
