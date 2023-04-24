/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:57:06 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:51:34 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	bytes;

	bytes = 0;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	while (s[bytes])
		bytes += ft_putchar_fd(s[bytes], fd);
	return (bytes);
}
