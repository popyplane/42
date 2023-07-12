/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:37:51 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/12 16:34:40 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

t_position	*get_size(char **map);
t_data	*get_data(char **map);
void check_data(t_data *data);
t_position	*get_position(char **map, char token);
t_map	init_map(char *map_ber);



#endif

