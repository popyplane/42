/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:19:27 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:50:01 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_tag(const char *format);
static int	print_data(va_list *xargs, char d);

int	ft_printf(const char *format, ...)
{
	int		bytes;
	va_list	xargs;

	bytes = 0;
	va_start(xargs, format);
	while (*format)
	{
		if (is_valid_tag(format))
		{
			bytes += print_data(&xargs, *++format);
			format++;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			bytes += ft_putchar_fd(*format++, 1);
			format++;
		}
		else
			bytes += ft_putchar_fd(*format++, 1);
	}
	return (bytes);
}

static int	is_valid_tag(const char *format)
{
	const char	*valid = "cspdiuxX";

	if (*format == '%' && *(format + 1) && ft_strchr(valid, *(format + 1)))
		return (1);
	return (0);
}

static int	print_data(va_list *xargs, char d)
{
	if (d == 'c')
		return (ft_putchar_fd(va_arg(*xargs, int), 1));
	if (d == 's')
		return (ft_putstr_fd(va_arg(*xargs, char *), 1));
	if (d == 'p')
		return (ft_putptr_fd(va_arg(*xargs, void *), 1));
	if (d == 'd' || d == 'i')
		return (ft_putnbr_fd(va_arg(*xargs, int), 1));
	if (d == 'u')
		return (ft_putunbr_fd(va_arg(*xargs, unsigned int), 1));
	if (d == 'x')
		return (ft_puthex_fd(va_arg(*xargs, unsigned int), 1));
	if (d == 'X')
		return (ft_puthex_up_fd(va_arg(*xargs, unsigned int), 1));
	return (0);
}
