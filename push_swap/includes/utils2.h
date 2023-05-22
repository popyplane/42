/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:39:07 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/05/22 15:46:37 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include "push_swap.h"

int	ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void    free_list(t_list *head);
void	ft_sort_two(t_list **lst);
void	print_list(t_list *a);


#endif