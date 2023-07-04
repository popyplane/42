/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:31 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/23 14:41:11 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *source, int value, size_t size)
{
	size_t		i;
	char		*buffer;

	i = 0;
	buffer = source;
	while (i < size)
	{
		*(buffer + i) = value;
		i++;
	}
	return (source);
}
