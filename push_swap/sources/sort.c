/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:28:49 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/17 17:14:38 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_list **a)
{
	if ((*a)->v < (*a)->n->v && (*a)->v > (*a)->n->n->v)
		return (rev_rotate(a, "rra"));
	else if ((*a)->v > (*a)->n->n->v && (*a)->n->v < (*a)->n->n->v)
		return (rotate(a, "ra"));
	else if ((*a)->v > (*a)->n->v && (*a)->n->v > (*a)->n->n->v)
		return (swap(a, "sa"), rev_rotate(a, "rra"));
	else if ((*a)->v < (*a)->n->v && (*a)->n->v > (*a)->n->n->v)
		return (swap(a, "sa"), rotate(a, "ra"));
	else if ((*a)->v > (*a)->n->v && (*a)->n->v < (*a)->n->n->v)
		return (swap(a, "sa"));
}

void	ft_sort_five(t_list **a, t_list **b)
{
	push(a, b, "pb");
	push(a, b, "pb");
	ft_sort_three(a);
	while ((*b) != NULL)
	{
		if (
			((*b)->v + 1 == (*a)->v)
			|| ((*b)->v == 0 && ft_lstlast(*a)->v == ft_highest_value(*a))
			|| ((*b)->v == 4 && ft_lstlast(*a)->v == ft_highest_value(*a))
		)
			push(b, a, "pa");
		else if (((*b)->v - 1 == (*a)->v))
		{
			rotate(a, "ra");
			push(b, a, "pa");
		}
		else
			rotate(a, "ra");
	}
	while (ft_get_index_of(*a, 0) > 2 && !ft_is_sorted(*a))
		rev_rotate(a, "rra");
	while (!ft_is_sorted(*a))
		rotate(a, "ra");
}

void    ft_radix(t_list **a, t_list **b, int size)
{
    int max_bin_length;
    int i;
    int j;

    max_bin_length = 0;
    while ((size - 1) >> max_bin_length != 0)
        max_bin_length++;
    i = -1;
    while (++i < max_bin_length - 1)
    {
        j = -1;
		while (++j < size)
		{
			if (((*a)->v >> i) & 1)
				rotate(a, "ra");
			else
				push(a, b, "pb");
		}
		while (*b != NULL)
			push(b, a, "pa");
	}
}

int	ft_get_index_of(t_list *lst, int value)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->v == value)
			return (i);
		lst = lst->n;
		i++;
	}
	return (-1);
}

int	ft_is_sorted(t_list *list)
{
	while (list != NULL)
	{
		if (list->n != NULL && list->v > list->n->v)
			return (0);
		list = list->n;
	}
	return (1);
}
