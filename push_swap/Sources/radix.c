/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:30:23 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/04/24 15:04:06 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void    ft_radix(t_list **a, t_list **b, int size)
{
    int max_bin_length;
    int i;
    int j;

    max_bin_length = 0;
    while ((size -1) >> max_bin_length != 0)
        max_bin_length++;
    i = -1;
    while (++i <= max_bin_length)
    {
        j = -1;
		while (++j < size)
		{
			if (((*a)->v >> i) & 1)
				ft_rotate(a, "ra");
			else
				ft_push(a, b, "pb");
		}
		while (*b != NULL)
			ft_push(b, a, "pa\n");
	}
}