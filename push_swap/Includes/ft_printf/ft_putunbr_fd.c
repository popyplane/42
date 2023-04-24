/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:46:13 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:51:15 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int uinb, int fd)
{
	if (uinb == 0)
		return (ft_putstr_fd("0", fd));
	return (ft_putnbr_base_fd(uinb, "0123456789", fd));
}
