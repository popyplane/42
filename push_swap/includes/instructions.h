/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:33:47 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/15 11:18:18 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "push_swap.h"

void	swap(t_list **a, char *str);
void	push(t_list **a, t_list **b, char *str);
void	rotate(t_list **a, char *str);
void	rev_rotate(t_list **a, char *str);

#endif