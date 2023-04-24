/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:05:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/04/24 15:02:21 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	t_list	*head;
	int		i;

	head = ft_lstnew(atoi(argv[1]));
	i = 1;
	while (++i < argc)
		ft_lstaddback(head, ft_lstnew(atoi(argv[i])));
	return (head);
}

int	*copy_as_tab(t_list *lst, int size)
{
	int	*tab;
	int	i;

	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		tab[i] = lst->v;
		lst = lst->n; 
	}
	return (tab);
}

void	sort_tab(int **tab)
{
	int	i;
	int temp;

	i = -1;
	while (tab[++i + 1])
	{
		if (*tab[i] > *tab[i + 1])
		{
			temp = *tab[i];
			*tab[i] = *tab[i + 1];
			*tab[i + 1] = temp;
			i = -1;
		}
	}
}

void	replace_args_by_indices(int *sorted_array, t_list *lst)
{
	int i;

	while (lst)
	{
		i = -1;
		while (sorted_array[++i])
			if (lst->v == sorted_array[i])
				lst->v = i;
		*lst = *lst->n; 
	}
}