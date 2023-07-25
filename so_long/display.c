/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:31:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 16:59:13 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "display.h"
#include "error.h"
#include "strings.h"
#include "structs.h"
#include "free.h"
#include "hooks.h"
#include <X11/X.h>
#include <X11/keysym.h>

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

void	display_score(t_mlx *mlx)
{
	char	*moves;
	char	*score_str;
	int		i;
	int		j;
	
	moves = ft_itoa(mlx->map->moves);
	if (!moves)
		ft_error(MALLOC_FAILURE);
	score_str = ft_strjoin("moves : ", moves);
	free(moves);
	if (!score_str)
		ft_error(MALLOC_FAILURE);
	i = -1;
	while (++i < mlx->map->map_size->x * TILE_SIZE)
	{
		j = -1;
		while (++j < SCORE_OFFSET)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, 0x00000000);
	}
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
						10, 30, 0x00FF0000, score_str);
	free(score_str);
}

int	ft_on_render(t_mlx *mlx)
{
	if (!mlx->win_ptr)
		return (0);
	display_score(mlx);
	render_bg(mlx);
	render_assets(mlx);
	return (0);
}

void	init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return(free_mlx(mlx), ft_error(EX11));
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, mlx->map->map_size->x * TILE_SIZE,
			mlx->map->map_size->y * TILE_SIZE + SCORE_OFFSET, "so_long");
	if (!mlx->win_ptr)
		return (ft_free_mlx(mlx), ft_free_mlx(mlx), ft_err(EX11));
	if (!ft_load_textures(mlx))
		return (ft_free_mlx(mlx), ft_free_mlx(mlx), ft_err(ETXTUR));
	mlx_loop_hook(mlx->mlx_ptr, &ft_on_render, mlx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, &ft_on_keypress, mlx);
	mlx_hook(
		mlx->win_ptr, DestroyNotify, StructureNotifyMask, &ft_on_close, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (ft_free_textures(mlx), ft_free_mlx(mlx), ft_free_mlx(mlx));
}