/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:43:53 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 17:03:32 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "free.h"
#include "structs.h"
#include "minilibx-linux/mlx.h"

void	ft_handle_move(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Up
		&& mlx->map->map[mlx->map->player_pos->y - 1][mlx->map->player_pos->x]
		!= WALL && ++mlx->map->moves
		&& ft_dprintf(1, "You have moved %d time(s).\n", mlx->map->moves))
		--mlx->map->player_pos->y;
	else if (keysym == XK_Down
		&& mlx->map->map[mlx->map->player_pos->y + 1][mlx->map->player_pos->x]
		!= WALL && ++mlx->map->moves
		&& ft_dprintf(1, "You have moved %d time(s).\n", mlx->map->moves))
		++mlx->map->player_pos->y;
	else if (keysym == XK_Left
		&& mlx->map->map[mlx->map->player_pos->y][mlx->map->player_pos->x - 1]
		!= WALL && ++mlx->map->moves
		&& ft_dprintf(1, "You have moved %d time(s).\n", mlx->map->moves))
		--mlx->map->player_pos->x;
	else if (keysym == XK_Right
		&& mlx->map->map[mlx->map->player_pos->y][mlx->map->player_pos->x + 1]
		!= WALL && ++mlx->map->moves
		&& ft_dprintf(1, "You have moved %d time(s).\n", mlx->map->moves))
		++mlx->map->player_pos->x;
}

int	ft_on_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		ft_on_close(mlx);
	else
		ft_handle_move(keysym, mlx);
	if (mlx->map->map[mlx->map->player_pos->y][mlx->map->player_pos->x] == EXIT
		&& mlx->map->data->collectible == 0)
	{
		ft_dprintf(1, "You win!\n");
		ft_dprintf(1, "Total moves: %d\n", mlx->map->moves);
		ft_on_close(mlx);
	}
	else if (mlx->map->map[mlx->map->player_pos->y][mlx->map->player_pos->x] == COLL)
	{
		--mlx->map->data->collectible;
		mlx->map->map[mlx->map->player_pos->y][mlx->map->player_pos->x] = FLOOR;
	}
	return (0);
}

int	ft_on_close(t_mlx *mlx)
{
	free_mlx(mlx);
	exit(0);
	return (0);
}