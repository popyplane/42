/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:13:02 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:47:59 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	ft_putstr_fd("0x", fd);
	return (ft_putnbr_base_fd((unsigned long)ptr, "0123456789abcdef", fd) + 2);
}
