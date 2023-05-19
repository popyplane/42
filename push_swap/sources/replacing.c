/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:15:14 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/19 20:45:12 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min_value(t_list *lst)
{
	int	min;

	min = ft_highest_value(lst);

	while (lst)
	{
		if (lst->v < min)
			min = lst->v;
		lst = lst->n;
	}
	return (min);
}

int	ft_next_min(t_list *lst, int last_min)
{
	int	next_min;

	next_min = ft_highest_value(lst);

	while (lst)
	{
		if (lst->v < next_min && lst->v > last_min)
			next_min = lst->v;
		lst = lst->n;
	}
	return (next_min);
}

int *indexing_stack(t_list *lst, int size)
{
    int sorted_index;
    int i;
    int current_value;
    int *indexed_tab;

    indexed_tab = malloc(size * sizeof(int));
    if (!indexed_tab)
        return (NULL);
    sorted_index = 0;
    current_value = ft_min_value(lst);
    while (sorted_index < size)
    {
        i = 0;
        while (lst->v != current_value)
        {
            lst = lst->n;
            i++;
        }
        indexed_tab[i] = sorted_index;
        sorted_index++;
        if (sorted_index < size)
            current_value = ft_next_min(lst, current_value);
    }
    return (indexed_tab);
}

void    replacing(t_list **lst, int *tab)
{
    while (*lst)
    {
        (*lst)->v = *tab;
        tab++;
        lst = (*lst)->n;
    }
}

// !!! MAKEFILE !!!