/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:27:29 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 16:19:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map(char *path)
{
	int	fd;
	int	map_row;
	char	*line;
	t_map	map;

	init_map(&map);
	get_map_dim(&map, path);
	map.map = malloc(sizeof(char *) * map.heigh); // need to implement a garbage collector
	// if !map.map ........
	fd = open(path, O_RDONLY);
	// if !fd .......
	line = get_next_line(fd);
	map_row = 0;
	while (line)
	{
		if (is_texture_line(line))
			get_texture_line(&map, line);
		else if (is_map_line(line))
			get_map_line(&map, line, &map_row);
		line = get_next_line(fd);
	}
	return (&map);
}

void	init_map(t_map *map)
{
	map = malloc(sizeof(t_map)); // need to implement a garbage collector
	// if !map .........
	map->heigh = 0;
	map->width = 0;
	map->texture = malloc(sizeof(t_texture)); // need to implement a garbage collector
}	

void	get_map_dim(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	//if (fd < 0)
		//error;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			map->heigh++;
			if (ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
		}
		get_next_line(fd);
	}
}