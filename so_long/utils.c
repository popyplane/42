/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:08 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 10:33:23 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "strings.h"
#include "ft_split.h"
#include "utils.h"

char	**ber_to_str(char *map)
{
	char	buffer[10000];
	char	*map_path;
	char	*c;
	int		reader;
	int		fd;
	int		i;

	c = NULL;
	map_path = ft_strjoin("/map/", map);
	fd = open(map_path, O_RDONLY, 0777);
	reader = 1;
	i = 0;
	while (reader)
	{
		reader = read(fd, c, 1);
		buffer[i] = *c;
		i++;
	}
	buffer[i] = '\0';
	return (ft_split(ft_strdup(buffer), '\n'));
}

static int	ft_intlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		sign;
	long	lnb;
	char	*nb_str;

	lnb = nbr;
	nb_str = malloc((ft_intlen(nbr) + 1) * sizeof(char));
	if (!nb_str)
		return (NULL);
	i = ft_intlen(lnb);
	nb_str[i] = '\0';
	sign = 0;
	if (lnb < 0)
	{
		lnb *= -1;
		sign++;
		nb_str[0] = '-';
	}
	while ((--i >= sign))
	{
		nb_str[i] = '0' + (lnb % 10);
		lnb /= 10;
	}
	return (nb_str);
}
