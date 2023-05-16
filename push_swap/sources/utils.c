/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:05:04 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/16 09:13:31 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*create_list(int argc, char **argv)
{
	t_list	*head;
	int		i;

	head = ft_lstnew(atoi(argv[1]));
	i = 1;
	ft_printf("\n\nhere we add %s\n\n", argv[i]);  // comment
	while (++i < argc)
	{
		ft_lstadd_back(&head, ft_lstnew(atoi(argv[i])));  
		ft_printf("\n\nhere we add %s\n\n", argv[i]);
	}
	return (head);
}

int	check_args(int argc, char **argv)
{
	int a;
	int	b;

	a = -1;
	while (++a < argc)
	{
		b = -1;
		while (argv[a][++b])
		{
			if (argv[a][b] != '-' && argv[a][b] < '0' && argv[a][b] > '9')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
		}
	}
	return (1);
}

int	*copy_as_tab(t_list *lst, int size)
{
	int	*tab;
	int	i;

	ft_printf("\n--------------------------------------------------");
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(tab + i) = lst->v;
		ft_printf("\ni = %d : tab[%d]= %d", i, i, tab[i]); // assignement des valeurs au tableau check le leak
		lst = lst->n;
		i++;
	}
	return (tab);
}

void	sort_tab(int **tab)
{
	int	i;
	int temp;

	i = 0;
	ft_printf("\ntab(%d)=%d ? tab(%d)=%d", i, *tab[i], i + 1, *tab[1]);  // probleme par ici
	while (**(tab + i + 1) != 0)
	{
		if (*tab[i] > *tab[i + 1])
		{
			temp = *tab[i];
			*tab[i] = *tab[i + 1];
			*tab[i + 1] = temp;
			i = 0;
		}
		i++;
		ft_printf("\ntab(%d)=%d ? tab(%d)=%d", i, *tab[i], i + 1, *tab[i + 1]);  // comment
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