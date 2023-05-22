/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:38:15 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/22 14:20:54 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ') && nptr[i])
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void    free_list(t_list *head)
{
    t_list *tmp;

    while (head)
    {
        tmp = head->n;
        free(head);
        head = tmp;
    }
}

void	ft_sort_two(t_list **lst)
{
	if (!ft_is_sorted(*lst))
		rotate(lst, "ra");
}

void	print_list(t_list *a)
{
	while (a)
	{
		ft_printf("- %d\n", a->v);
		a = a->n;
	}
	ft_printf("\n");
}