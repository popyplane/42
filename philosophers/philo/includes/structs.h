/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:57:47 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/12 18:15:25 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../includes.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct timeval	t_timeval;

typedef struct s_input
{
	int	nb_of_philo;
	int	time_to_die_ms;
	int	time_to_eat_ms;
	int	time_to_sleep_ms;
	int max_meal;
}	t_input;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_data			*data;
	unsigned long	last_meal_time_ms;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	fork_l;
}	t_philo;

typedef struct s_data
{
	t_input			*rules;
	unsigned long	start_time_ms;
	t_philo			*philo;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_mutex;
}	t_data;

#endif