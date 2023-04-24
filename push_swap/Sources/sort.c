/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:28:49 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/04/24 15:03:11 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_sort_three(t_list **a)
{
	if ((*a)->v < (*a)->n->v && (*a)->v > (*a)->n->n->v)
		return (ft_reverse_rotate(a, "rra\n"));
	else if ((*a)->v > (*a)->n->n->v && (*a)->n->v < (*a)->n->n->v)
		return (ft_rotate(a, "ra\n"));
	else if ((*a)->v > (*a)->n->v && (*a)->n->v > (*a)->n->n->v)
		return (ft_swap(a, "sa\n"), ft_reverse_rotate(a, "rra\n"));
	else if ((*a)->v < (*a)->n->v && (*a)->n->v > (*a)->n->n->v)
		return (ft_swap(a, "sa\n"), ft_rotate(a, "ra\n"));
	else if ((*a)->v > (*a)->n->v && (*a)->n->v < (*a)->n->n->v)
		return (ft_swap(a, "sa\n"));
}

void	ft_sort_five(t_list **a, t_list **b)
{
	ft_push(a, b, "pb\n");
	ft_push(a, b, "pb\n");
	ft_sort_three(a);
	while ((*b) != NULL)
	{
		if (
			((*b)->v + 1 == (*a)->v)
			|| ((*b)->v == 0 && ft_lstlast(*a)->v == ft_highest_value(*a))
			|| ((*b)->v == 4 && ft_lstlast(*a)->v == ft_highest_value(*a))
		)
			ft_push(b, a, "pa\n");
		else if (((*b)->v - 1 == (*a)->v))
		{
			ft_rotate(a, "ra\n");
			ft_push(b, a, "pa\n");
		}
		else
			ft_rotate(a, "ra\n");
	}
	while (ft_get_index_of(*a, 0) > 2 && !ft_is_sorted(*a))
		ft_reverse_rotate(a, "rra\n");
	while (!ft_is_sorted(*a))
		ft_rotate(a, "ra\n");
}