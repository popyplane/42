/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:02:45 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:41:03 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "strings.h"
#include "structs.h"
#include "utils.h"
#include "error.h"
#include "free.h"
#include "texture.h"
#include "print.h"
#include "utils.h"
#include <stdlib.h>

// get the size of the map and return it's values,
// return {-1, -1} if map isn't rectangular
t_position	*get_size(char **map)
{
	t_position	*size_max;
	t_position	*err;

	size_max = malloc(sizeof(t_position));
	if (!size_max)
		ft_error(MALLOC_FAILURE);
	err = malloc(sizeof(t_position));
	if (!err)
		ft_error(MALLOC_FAILURE);
	err->x = -1;
	err->y = -1;
	size_max->x = ft_strlen(*map);
	size_max->y = 0;
	while (map[size_max->y])
	{
		if ((int)ft_strlen(map[size_max->y]) != size_max->x)
		{
			free(size_max);
			return (err);
		}
		size_max->y++;
	}
	free(err);
	return (size_max);
}

// counts the number of exit, player and collectibles
t_data	*get_data(char **map)
{
	t_data	*data;
	int		x;
	int		y;

	data = init_data();
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E'
				&& map[y][x] != '0' && map[y][x] != '1')
				ft_error(UNK_DATA);
			if (map[y][x] == 'P')
				data->start++;
			if (map[y][x] == 'C')
				data->collectible++;
			if (map[y][x] == 'E')
				data->exit++;
		}
	}
	return (data);
}

void	check_data(t_data *data)
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
	t_position	*pos;

	pos = malloc(sizeof(t_position));
	if (!pos)
		return (0);
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
	free(pos);
	ft_error("The token hasn't been found");
	return (0);
}

t_map	*init_map(char *map_ber)
{
	t_map	*map;
	char	**dup_map;
	t_data	*flood;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(MALLOC_FAILURE);
	map->moves = 0;
	map->map = ber_to_str(map_ber);
	dup_map = ber_to_str(map_ber);
	init_map_bases(map);
	flood = init_data();
	if (!fill_flood(map, map->player_pos->x, map->player_pos->y, flood))
		ft_error(REACH);
	free(flood);
	free_array(map->map);
	free(map->map);
	map->map = dup_map;
	if (!check_around_walls(map))
		ft_error(SIDEWALL);
	return (map);
}
