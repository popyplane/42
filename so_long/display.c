/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:31:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/24 18:06:36 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "structs.h"

void	render_assets(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->map_size->y)
	{
		j = -1;
		while (++j < mlx->map->map_size->x)
		{
			if (mlx->map->map[i][j] == COLL)
				mlx_put_image_to_window(
					mlx->mlx_ptr, mlx->win_ptr, mlx->textures[2],
					j * TILE_SIZE, i * TILE_SIZE + SCORE_OFFSET);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->textures[4],
						mlx->map->exit->x * TILE_SIZE,
						mlx->map->exit->y * TILE_SIZE + SCORE_OFFSET);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->textures[3],
						mlx->map->player_pos->x * TILE_SIZE,
						mlx->map->player_pos->y * TILE_SIZE + SCORE_OFFSET);
}

void	render_bg(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->map_size->y)
	{
		j = -1;
		while (++j < mlx->map->map_size->x)
		{
			if (mlx->map->map[i][j] == FLOOR)
				mlx_put_image_to_window(
					mlx->mlx_ptr, mlx->win_ptr, mlx->textures[0],
					j * TILE_SIZE, i * TILE_SIZE + SCORE_OFFSET);
			else
				mlx_put_image_to_window(
					mlx->mlx_ptr, mlx->win_ptr, mlx->textures[1],
					j * TILE_SIZE, i * TILE_SIZE + SCORE_OFFSET);
		}
	}
}