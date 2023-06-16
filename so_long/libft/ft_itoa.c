/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:37:26 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/18 14:17:45 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		sign;
	long	lnb;
	char	*nb_str;

	lnb = nbr;
	nb_str = malloc((ft_intlen(nbr) + 1) * sizeof(char));
	if (!nb_str)
		return (NULL);
	i = ft_intlen(lnb);
	nb_str[i] = '\0';
	sign = 0;
	if (lnb < 0)
	{
		lnb *= -1;
		sign++;
		nb_str[0] = '-';
	}
	while ((--i >= sign))
	{
		nb_str[i] = '0' + (lnb % 10);
		lnb /= 10;
	}
	return (nb_str);
}
