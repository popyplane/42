/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:02:45 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/12 16:36:46 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "structs.h"
#include "utils.c"
#include "error.h"

// get the size of the map and return it's values, return {-1, -1} if map isn't rectangular
t_position	*get_size(char **map)
{
	t_position	*size_max;
	t_position	*err;

	err->x = -1;
	err->y = -1;
	size_max->x = ft_strlen(*map);
	size_max->y = 0;
	while(map[size_max->y])
	{
		if (ft_strlen(map[size_max->y]) != size_max->x)
			return (err);
		size_max->y++;
	}
	return (size_max);
}

// counts the number of exit, player and collectibles
t_data	*get_data(char **map)
{
	t_data	*data;
	int		x;
	int		y;

	data->exit = 0;
	data->start = 0;
	data->collectible = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				data->start++;
			if (map[y][x] == 'C')
				data->collectible++;
			if (map[y][x] == 'E')
				data->exit++;
			x++;
		}
		y++;
	}
	return (data);
}

void check_data(t_data *data)
{
	if (data->start > 1)
		ft_error(EXCESS_P);
	if (data->start == 0)
		ft_error(NO_P);
	if (data->exit > 1)
		ft_error(EXCESS_E);
	if (data->exit == 0)
		ft_error(NO_E);
	if (data->collectible == 0)
		ft_error(NO_C);
}

t_position	*get_position(char **map, char token)
{
	t_position *pos;

	pos->y = 0;
	while (map[pos->y])
	{
		pos->x = 0;
		while (map[pos->y][pos->x])
		{
			if (map[pos->y][pos->x] == token)
				return (pos);
			pos->x++;
		}
		pos->y++;
	}
	ft_error("The token hasn't been found");
}

t_map	init_map(char *map_ber)
{
	t_map	*map;

	map->map = ber_to_str(map_ber);
	map->map_size = get_size(map->map);
		if (map->map_size->y == -1)
			ft_error(RCTGL);										
	map->data = get_data(map->map);
	check_data(map->data);
	map->exit = get_position(map-map, 'E');
	map->player_pos = get_position(map-map, 'P');
}
