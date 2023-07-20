/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:34:56 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/19 13:35:32 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "map.h"
#include "strings.h"
#include "error.h"
#include <string.h>

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

t_bool	is_step_possible(t_map *map, int x, int y)
{
	if (map->map[y][x] == WALL)
		return (false);
	else if (map->map[y][x] == EMPTY || map->map[y][x] == EXIT)
		return (true);
	else if (map->map[y][x] = COLL)
	{
		map->data->collectible--;
		return (true);
	}
}

t_bool	fill_flood(t_map *data, char **map, int x, int y)
{
	if (data->exit->x == x && data->exit->y == y
			&& data->data->collectible == 0)
		return (true);
	map[y][x] = WALL;
	map[data->exit->y][data->exit->x] = EXIT;
	data->player_pos->x = x;
	data->player_pos->y = y;
	if (is_step_possible(map, x + 1, y))
		if (fill_flood(data, map, x + 1, y))
			return (true);
	else if (is_step_possible(map, x, y + 1))
		if (fill_flood(data, map, x + 1, y))
			return (true);
	else if (is_step_possible(map, x - 1, y))
		if (fill_flood(data, map, x - 1, y))
			return (true);
	else if (is_step_possible(map, x, y -1))
		if (fill_flood(data, map, x, y - 1))
			return (true);
	return (false);
}

void copy_position(t_position *old, t_position *new)
{
	new->x = old->x;
	new->y = old->y;
}

t_map copy_map(t_map *map)
{
	t_map	*ret;
	int		y;

	ret->data = map->data;
	ret->moves = map->moves;
	ret->map = malloc((map->map_size->y + 1) * sizeof(char *));
	if (!ret->map)
		return (ft_error(MALLOC_FAILURE));
	y = -1;
	while (++y < map->map_size->y)
		ret->map[y] = ft_strdup(map->map[y]);
	ret->map[y] = NULL;
	copy_position(map->map_size, ret->map_size);
	copy_position(map->exit, ret->exit);
	copy_position(map->player_pos, ret->player_pos);
	ret->is_valid = map->is_valid;
}