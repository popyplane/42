/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/23 15:46:09 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, unsigned int size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = -1;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (0);
	if (size < dest_len || !size)
		return (size + src_len);
	while (src[++i] && i + 1 < (size - dest_len))
		dst[dest_len + i] = src[i];
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
