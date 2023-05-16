/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:29:31 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/15 11:54:50 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

void	ft_sort_three(t_list **a);
void	ft_sort_five(t_list **a, t_list **b);
void    ft_radix(t_list **a, t_list **b, int size);
int     ft_get_index_of(t_list *lst, int value);
int     ft_is_sorted(t_list *list);


#endif