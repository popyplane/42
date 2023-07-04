/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:04:52 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/23 15:35:46 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	if (!len)
		return (0);
	while (*big && len--)
	{
		if (!ft_strncmp(big, little, ft_strlen(little))
			&& ft_strlen(little) <= len + 1)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
