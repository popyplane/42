/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:58:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/15 16:55:04 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    int *tab;

    if (!check_args(argc, argv))
        return (0);
    a = create_list(argc, argv);
    b = a;
    while (b != NULL)
    {
        ft_printf("\nb -> %d", b->v);
        b = b->n;
    }
    tab = copy_as_tab(a, argc - 1);
    ft_printf("\n-->tab[0]=%d\ntab[1]=%d\ntab[2]=%d", tab[0], tab[1], tab[2]);
    sort_tab(&tab);
    replace_args_by_indices(tab, a);
    free(tab);
    if (argc == 3)
        ft_sort_three(&a);
    else if (argc == 5)
        ft_sort_five(&a, &b);
    else
        ft_radix(&a, &b, argc);
    return (0);
}