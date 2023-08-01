/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:44:59 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/28 11:31:45 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "structs.h"

void	free_array(char	**array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
}

void	free_map(t_map *map)
{
	free_array(map->map);
	free(map->data);
	free(map->map_size);
	free(map->exit);
	free(map->player_pos);
	free(map);
}

void	free_mlx(t_mlx *mlx)
{
	int	i;
	
	free_map(mlx->map);
	i = -1;
	while (++i < 5)
		free(mlx->textures[i]);
	if (mlx->mlx_ptr)
	{
		if (mlx->win_ptr)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
}
