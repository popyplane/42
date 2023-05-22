/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:15:14 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/22 14:17:41 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min_value(t_list *lst)
{
	int	min;
    t_list *tmp;

    tmp = lst;
	min = ft_highest_value(lst);

	while (lst)
	{
		if (lst->v < min)
			min = lst->v;
		lst = lst->n;
	}
    lst = tmp;
	return (min);
}

int	ft_next_min(t_list *lst, int last_min)
{
	int	next_min;
    t_list *tmp;

	tmp = lst;
    next_min = ft_highest_value(lst);
    // ft_printf("highest value = %d\n", next_min);

	while (lst)
	{
		if (lst->v < next_min && lst->v > last_min)
			next_min = lst->v;
		lst = lst->n;
	}
    // ft_printf("next_min = %d\n", next_min);
    lst = tmp;
	return (next_min);
}

int *indexing_stack(t_list *lst, int size)
{
    int sorted_index;
    int i;
    int current_value;
    int *indexed_tab;
    t_list *tmp;

    tmp = lst;
    indexed_tab = malloc(size  * sizeof(int));
    if (!indexed_tab)
        return (NULL);
    sorted_index = 0;
    current_value = ft_min_value(lst);
    while (sorted_index < size)
    {
        lst = tmp;
        i = 0;
        // ft_printf("current_value = %d\n", current_value);
        while (lst->v != current_value)
        {
            lst = lst->n;
            i++;
        }
        lst = tmp;
        // ft_printf("sorted_index = %d, i = %d, current_value = %d\n", sorted_index, i, current_value);
        indexed_tab[i] = sorted_index;
        sorted_index++;
        // ft_printf("before = %d\n", current_value);
        if (sorted_index < size)
            current_value = ft_next_min(lst, current_value);
    }
    return (indexed_tab);
}

void    replacing(t_list **lst, int *tab)
{
    t_list *tmp;
    int i;

    tmp = *lst;
    // print_list(*lst);
    i = 0;
    while (*lst)
    {
        (*lst)->v = tab[i];
        i++;
        (*lst) = (*lst)->n;
    }
    *lst = tmp;
    // print_list(*lst);
}

// !!! MAKEFILE !!!