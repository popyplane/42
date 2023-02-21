/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:00 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/21 19:33:05 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/instructions.h"

void	swap(t_list **a, char *str)
{
	t_list	*tmp;

	tmp = (*a)->next->next;
	(*a)->next->next = *a;
	(*a)->next = tmp;
	ft_printf("%s\n", str);
}

void	push(t_list **a, t_list **b, char *str)
{
	t_list	*tmp;
	
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_printf("%s\n", str);
}

void	rotate(t_list **a, char *str)
{
	t_list	*tmp;
	
	tmp = (*a)->next;
	ft_lstadd_back(a, a);
	(*a)->next = NULL;
	*a = tmp;
	ft_printf("%s\n", str);
}

void	rev_rotate(t_list **a, char *str)
{
	t_list	*cursor;

	if ((*a)->next == NULL)
		return;
	cursor = *a;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next->next = *a;
	*a = cursor->next;
	cursor->next = NULL;
	ft_printf("%s\n", str);
}