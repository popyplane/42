/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:51 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/28 14:50:14 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "map.h"
#include "strings.h"
#include "structs.h"
#include "utils.h"
#include "error.h"
#include <stdlib.h>

t_position	*get_size(char **map);
t_data		*get_data(char **map);
void		check_data(t_data *data);
t_position	*get_position(char **map, char token);
t_map		*init_map(char *map_ber);

t_bool	check_around_walls(t_map *map);
t_bool	is_step_possible(t_map *data, char **map, int x, int y);
t_bool	fill_flood(t_map *map, int px, int py, t_data *flood);
void	copy_position(t_position *old, t_position *new);

#endif

