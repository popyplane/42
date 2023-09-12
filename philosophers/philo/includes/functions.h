/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:57:07 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/12 17:28:05 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "../includes.h"

/**
 * ----- init.c ------
*/
void			init_data(t_data *data);
t_bool			parse_input(int argc, char **argv, t_data *data);

/**
 * ----- utils.c -----
*/
int				ft_atoi(char *str);

/**
 * ----- time.c -----
*/
unsigned long	ft_get_time_in_ms(void);
int				ft_get_time_diff(unsigned long time);
int				ft_get_rounded_time_diff(unsigned long time, int round);
void			ft_usleep(unsigned long time);


#endif