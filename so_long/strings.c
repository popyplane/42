/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:56:43 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/20 14:59:15 by bvieilhe         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		new_str = malloc(sizeof(char));
	else if (start + len > ft_strlen(s))
		new_str = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && s[i + start] && i < len)
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}