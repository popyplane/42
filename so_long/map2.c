/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:34:56 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/28 14:49:54 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "strings.h"
#include "structs.h"
#include "print.h"
#include "utils.h"
#include "texture.h"
#include "error.h"
#include <stdlib.h>

t_bool	check_around_walls(t_map *map)
{
	int	x;
	int	y;

	while (x < map->map_size->x)
	{
		if (map->map[0][x] != WALL || map->map[map->map_size->y - 1][x] != WALL)
			return (false);
		x++;
	}
	while (y < map->map_size->y)
	{
		if (map->map[y][0] != WALL || map->map[y][map->map_size->x - 1] != WALL)
			return (false);
		y++;
	}
	return (true);
}

t_bool	is_step_possible(t_map *data, char **map, int x, int y)
{
	if (x < 0 || x >= data->map_size->x - 1
		|| y < 0 || y >= data->map_size->y - 1)
		return (false);
	if (map[y][x] == WALL)
		return (false);
	if (map[y][x] == FLOOR || map[y][x] == EXIT)
		return (true);
	if (map[y][x] == COLL)
	{
		data->data->collectible--;
		return (true);
	}
	ft_dprintf(1, "THE ERROR : %c, x = %d, y = %d\n", map[y][x], x, y);
	ft_error(UNK_DATA);
	return (false);
}

t_bool	fill_flood(t_map *map, int px, int py, t_data *flood)
{
	if (flood->collectible == map->data->collectible && flood->exit == 1)
		return (true);
	if (map->map[py][px] == WALL)
		return (false);
	if (map->map[py][px] == COLL)
		flood->collectible++;
	if (map->map[py][px] == EXIT)
		flood->exit++;
	map->map[py][px] = WALL;
	if (fill_flood(map, px + 1, py, flood) == true
		|| fill_flood(map, px - 1, py, flood) == true
		|| fill_flood(map, px, py + 1, flood) == true
		|| fill_flood(map, px, py - 1, flood) == true)
		return (true);
	return (false);
	// if (data->exit->x == x && data->exit->y == y
	// 		&& data->data->collectible == 0)
	// 	return (true);
	// map[y][x] = WALL;
	// map[data->exit->y][data->exit->x] = EXIT;
	// data->player_pos->x = x;
	// data->player_pos->y = y;
	// if (is_step_possible(data, map, x + 1, y))
	// 	if (fill_flood(data, map, x + 1, y))
	// 		return (true);
	// if (is_step_possible(data, map, x, y + 1))
	// 	if (fill_flood(data, map, x + 1, y))
	// 		return (true);
	// if (is_step_possible(data, map, x - 1, y))
	// 	if (fill_flood(data, map, x - 1, y))
	// 		return (true);
	// if (is_step_possible(data, map, x, y - 1))
	// 	if (fill_flood(data, map, x, y - 1))
	// 		return (true);
	// return (false);
}

void	copy_position(t_position *old, t_position *new)
{
	new->x = old->x;
	new->y = old->y;
}

// t_map	*copy_map(t_map *map)
// {
// 	t_map	*ret;
// 	int		y;

// 	ret = malloc(sizeof(t_map));
// 	if (!ret)
// 		ft_error(MALLOC_FAILURE);
// 	malloc_pos(ret);
// 	ret->data = map->data;
// 	ret->moves = map->moves;
// 	ret->map = malloc((map->map_size->y + 1) * sizeof(char *));
// 	if (!ret->map)
// 	{
// 		free(ret);
// 		ft_error(MALLOC_FAILURE);
// 	}
// 	y = -1;
// 	while (++y < map->map_size->y)
// 		ret->map[y] = ft_strdup(map->map[y]);
// 	ret->map[y] = NULL;
// 	copy_position(map->map_size, ret->map_size);
// 	copy_position(map->exit, ret->exit);
// 	copy_position(map->player_pos, ret->player_pos);
// 	ret->is_valid = map->is_valid;
// 	return(ret);
// }