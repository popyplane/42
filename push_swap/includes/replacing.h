/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:15:50 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/22 11:54:28 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACING_H
# define REPLACING_H

# include "push_swap.h"

int	ft_min_value(t_list *lst);
int	ft_next_min(t_list *lst, int last_min);
int *indexing_stack(t_list *lst, int size);
void    replacing(t_list **lst, int *tab);

#endif