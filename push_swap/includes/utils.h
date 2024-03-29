/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:07:44 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/17 11:33:53 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "push_swap.h"

t_list	*create_list(int argc, char **argv);
int     check_args(int argc, char **argv);
int		*copy_as_tab(t_list *lst, int size);
void	sort_tab(int *tab, int size);
void	replace_args_by_indices(int *sorted_array, int size, t_list *lst);

#endif