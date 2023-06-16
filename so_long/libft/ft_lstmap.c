/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:19:33 by bvieilhe          #+#    #+#             */
/*   Updated: 2022/11/23 15:14:11 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*lst_bis;

	if (!lst || !f || !del)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (NULL);
	lst_bis = new_head;
	lst = lst->next;
	while (lst)
	{
		lst_bis->next = ft_lstnew(f(lst->content));
		if (!lst_bis)
		{
			ft_lstclear(&lst_bis, del);
			return (NULL);
		}
		lst_bis = lst_bis->next;
		lst = lst->next;
	}
	lst_bis->next = NULL;
	return (new_head);
}
