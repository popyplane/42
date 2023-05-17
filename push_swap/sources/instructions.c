/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:00 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/17 16:15:48 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **a, char *str)
{
	t_list	*tmp;

	tmp = (*a)->n->n;
	(*a)->n->n = *a;
	(*a)->n = tmp;
	ft_printf("%s\n", str);
}

void	push(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;
	
	if (!b)
	{
		*b = ft_lstnew((*a)->v);
		tmp = (*a)->n;
		free(*a);
		*a = tmp;
	}
	tmp = (*a)->n;
	(*a)->n = *b;
	*b = *a;
	*a = tmp;
	ft_printf("%s\n", str);
}

void	rotate(t_list **a, char *str)
{
	t_list	*tmp;
	
	tmp = (*a)->n;
	ft_lstadd_back(a, *a);
	(*a)->n = NULL;
	*a = tmp;
	ft_printf("%s\n", str);
}

void	rev_rotate(t_list **a, char *str)
{
	t_list	*last;
	t_list	*second_last;

	second_last = *a;
	last = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(last->v));
	while (second_last->n->n)
		second_last = second_last->n;
	free(second_last->n);
	second_last->n = NULL;
	ft_printf("%s\n", str);
}
