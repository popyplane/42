/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:05:52 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:53:33 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkbase(char *str);
static int	ft_print_recursive(unsigned long ulnb, char *base, int fd);

int	ft_putnbr_base_fd(unsigned long ulnb, char *base, int fd)
{
	if (ft_checkbase(base) == 0)
		return (0);
	if (ulnb == 0)
		return (ft_putchar_fd(base[0], fd));
	return (ft_print_recursive(ulnb, base, fd) - 1);
}

static int	ft_checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (str[i + 1])
	{
		j = 1;
		while (str[i + j])
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_print_recursive(unsigned long ulnb, char *base, int fd)
{
	int	bytes;

	bytes = 1;
	if (ulnb)
	{
		bytes += ft_print_recursive(ulnb / ft_strlen(base), base, fd);
		ft_putchar_fd(base[ulnb % ft_strlen(base)], fd);
	}
	return (bytes);
}
