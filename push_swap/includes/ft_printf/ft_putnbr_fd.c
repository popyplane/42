/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:05:52 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:54:11 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	long long	llnb;

	llnb = nb;
	if (llnb < 0)
	{
		ft_putchar_fd('-', fd);
		llnb *= -1;
		return (ft_putnbr_base_fd(llnb, "0123456789", fd) + 1);
	}
	return (ft_putnbr_base_fd(llnb, "0123456789", fd));
}
