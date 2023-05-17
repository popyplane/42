/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:58:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/17 17:13:53 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    int     *tab;

    if (!check_args(argc, argv))
        return (0);
    a = create_list(argc, argv);
    b = NULL;
    tab = copy_as_tab(a, argc - 1);
    sort_tab(tab, argc - 1);
    replace_args_by_indices(tab, argc - 1, a);
    free(tab);
    if (argc - 1 == 2)
        ft_sort_two(&a);
    else if (argc - 1 == 3)
        ft_sort_three(&a);
    else if (argc - 1 == 5)
        ft_sort_five(&a, &b);
    else
        ft_radix(&a, &b, argc);
    free_list(a);
    free_list(b);
    return (0);
}