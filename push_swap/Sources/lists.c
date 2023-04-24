/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:30:11 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/04/24 15:01:40 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->v = content;
	new->n = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->n = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->n = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->n)
		lst = lst->n;
	return (lst);
}
