/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:41:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:47:17 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned int uinb, int fd)
{
	return (ft_putnbr_base_fd(uinb, "0123456789abcdef", fd));
}
