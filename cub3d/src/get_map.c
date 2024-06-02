/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:27:29 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 16:10:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map(char *path)
{
	int	fd;
	int	map_row;
	char	*line;
	t_map	*map;

	map = NULL;
	ft_printf("start\n"); // test
	init_map(map);
	ft_printf("init ok\n"); // test
	//ft_printf("map heigh = %d\n", map->heigh); //test
	//ft_printf("map width = %d\n", map->width); //test
	get_map_dim(map, path);
	ft_printf("dim ok\n"); // test
	map->map = malloc(sizeof(char *) * map->heigh); // need to implement a garbage collector
	// if !map.map ........
	fd = open(path, O_RDONLY);
	// if !fd .......
	line = get_next_line(fd);
	map_row = 0;
	while (line)
	{
		if (is_texture_line(line))
			get_texture_line(map, line);
		else if (is_map_line(line))
			get_map_line(map, line, &map_row);
		line = get_next_line(fd);
	}
	ft_printf("get_map ok\n");
	return (map);
}

void	init_map(t_map *map)
{
	map = malloc(sizeof(t_map)); // need to implement a garbage collector
	// if !map .........
	map->heigh = 0;
	ft_printf("heigh set to %d", map->heigh);
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
		if (*line != '\n' && is_map_line(line))
		{
			ft_printf("###### inside a map line\n"); //test
			(map->heigh)++;
			ft_printf("actual heigh = %d", map->heigh); //test
			if ((int)ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
		}
		ft_printf("line = "); //test
		ft_printf(line); //test
		line = get_next_line(fd);
		ft_printf("next line = "); //test
		ft_printf(line); //test
	}
}