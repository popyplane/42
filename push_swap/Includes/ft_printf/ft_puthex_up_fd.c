/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_up_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:11:23 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:42:45 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up_fd(unsigned int uinb, int fd)
{
	return (ft_putnbr_base_fd(uinb, "0123456789ABCDEF", fd));
}
