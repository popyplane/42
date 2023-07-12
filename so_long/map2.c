/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:34:56 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/12 17:06:17 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "map.h"

t_bool	check_around_walls(t_map *map)
{
	int	x;
	int	y;

	while (x < map->map_size->x)
	{
		if (map->map[0][x] != 1 || map->map[map->map_size->y - 1][x] != 1)
			return (false);
		x++;
	}
	while (y < map->map_size->y)
	{
		if (map->map[y][0] != 1 || map->map[y][map->map_size->x - 1] != 1)
			return (false);
		y++;
	}
	return (true);
}

