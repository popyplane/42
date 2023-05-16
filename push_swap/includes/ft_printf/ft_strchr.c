/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/12/22 15:30:25 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	if (c == 0)
		return ((char *)(buffer + ft_strlen((char *)buffer)));
	while (*buffer)
	{
		if (*buffer == (c % 256))
			return ((char *)buffer);
		buffer++;
	}
	return (NULL);
}
