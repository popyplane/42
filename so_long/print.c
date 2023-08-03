/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:26:19 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:41:30 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "print.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

static int	ft_parse_special_chars(char c, va_list *ap, int fd);

int	ft_dprintf(int fd, const char *format, ...)
{
	int			bytes;
	va_list		ap;
	char		*legal_flags;

	bytes = 0;
	va_start(ap, format);
	legal_flags = "csdi%";
	while (*format)
	{
		if (*format == '%' && *(format + 1)
			&& ft_strchr((const char *)legal_flags, *(format + 1)))
		{
			bytes += ft_parse_special_chars(*++format, &ap, fd);
			format++;
		}
		else
			bytes += ft_putchar_fd(*format++, fd);
	}
	va_end(ap);
	return (bytes);
}

static int	ft_parse_special_chars(char c, va_list *ap, int fd)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), fd));
	if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int nb, int fd)
{
	int	bytes;

	bytes = 0;
	if (nb == -2147483648)
		bytes += ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			bytes += ft_putchar_fd('-', fd);
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			bytes += ft_putchar_fd('0' + (nb % 10), fd);
		}
		else
			bytes += ft_putchar_fd('0' + nb, fd);
	}
	return (bytes);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	bytes;

	bytes = 0;
	while (*s)
	{
		bytes += ft_putchar_fd(*s, fd);
		s++;
	}
	return (bytes);
}
