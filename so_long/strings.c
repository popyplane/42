/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:56:43 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/06 13:32:34 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "strings.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	int			i;
	int const	s1_len = ft_strlen((char *)s1);
	int const	s2_len = ft_strlen((char *)s2);

	new_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)   
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	new_str[s1_len + i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	dest = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < ft_strlen((char *)str))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}