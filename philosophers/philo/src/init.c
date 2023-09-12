/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:25:51 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/12 18:17:01 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	init_data(t_data *data)
{
	data->rules->nb_of_philo = 0;
	data->rules->time_to_die_ms = 0;
	data->rules->time_to_eat_ms = 0;
	data->rules->time_to_sleep_ms = 0;
	data->rules->max_meal = -1;
	data->start_time_ms = 0;
	data->philo = NULL;
}

t_bool	parse_input(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (false);
	data->rules->nb_of_philo = ft_atoi(argv[1]);
	data->rules->time_to_die_ms = ft_atoi(argv[2]);
	data->rules->time_to_eat_ms = ft_atoi(argv[3]);
	data->rules->time_to_sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
		data->rules->max_meal = ft_atoi(argv[5]);
	if (data->rules->nb_of_philo < 1
		|| data->rules->time_to_die_ms < 1
		|| data->rules->time_to_eat_ms < 1
		|| data->rules->time_to_sleep_ms < 1
		|| (argc == 6 && data->rules->max_meal < 1))
		return (false);
	return (true);
}

void	init_philo(t_data *data, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < data->rules->nb_of_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].fork_l = fork[i];
		data->philo[i].fork_r = fork[(i + 1) % data->rules->nb_of_philo];
	}
}
