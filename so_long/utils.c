/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/12 13:32:50 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "strings.h"
#include "utils.h"

char	**ber_to_str(char *map)
{
	char	buffer[10000];
	char	*map_path;
	char	c;
	int		reader;
	int		fd;
	int		i;

	map_path = ft_strjoin("/map/", map);
	fd = open(map_path, O_RDONLY, 0777);
	reader = 1;
	i = 0;
	while (reader)
	{
		reader = read(fd, c, 1);
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	return (ft_split(ft_strdup(buffer)));
}