/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:00 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/15 11:32:17 by bvieilhe         ###   ########.fr       */
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
	t_list	*cursor;

	if ((*a)->n == NULL)
		return;
	cursor = *a;
	while (cursor->n)
		cursor = cursor->n;
	cursor->n->n = *a;
	*a = cursor->n;
	cursor->n = NULL;
	ft_printf("%s\n", str);
}