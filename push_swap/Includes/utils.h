/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:07:44 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/21 18:42:32 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "lists.h"
# include "sort.h"
# include "instructions.h"


t_list	*create_list(int argc, char **argv);
int		*copy_as_tab(t_list *lst, int size);
void	sort_tab(int **tab);
void	replace_args_by_indices(int *sorted_array, t_list *lst);

#endif