/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:06:48 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/22 22:24:24 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clear.h"

void	    *garbage_collector(void *ptr, bool clean);

static void	delete(void *ptr);

void	*garbage_collector(void *ptr, bool clean)
{
	static t_list	*garbage_list;

	if (clean)
	{
		ft_lstclear(&garbage_list, delete);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
		return (ptr);
	}
}

static void	delete(void *ptr)
{
	free(ptr);
	ptr = NULL;
}