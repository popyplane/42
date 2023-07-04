/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:55 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/23 14:50:13 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buffer;

	buffer = ((char *)s);
	i = ft_strlen(buffer);
	if (c == 0)
		return (buffer + ft_strlen(buffer));
	while (i >= 0)
	{
		if (*(buffer + i) == (c % 256))
			return (buffer + i);
		i--;
	}
	return (NULL);
}
