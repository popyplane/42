/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:00:23 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/12 18:22:02 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"


t_bool	spawn_threads(t_data *data)
{
	int	i;

	if (!init_mutexes(&data))
		return (false);
	i = -1;
	while (++i < data->rules->nb_of_philo)
	{
		if (pthread_create(data->philo->thread, NULL,
				&redirect_philo, &data->philo[i]))
			return (false);
	}
	pthread_mutex_lock(&data->data_mutex);
	data->start_time_ms = ft_get_time_in_ms;
	i = -1;
	while (++i < data->rules->nb_of_philo)
		data->philo[i].last_meal_time_ms = data->start_time_ms;
	pthread_mutex_unlock(&data->data_mutex);
}

static t_bool	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->rules->nb_of_philo)
	{
		if (pthread_mutex_init(&data->philo[i].fork_l, NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (false);
	return (true);
}

static void	*redirect_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->rules->nb_of_philo == 1)
		ft_single_philo(philo);
	else
		ft_multiple_philos(philo);
	return (NULL);
}

