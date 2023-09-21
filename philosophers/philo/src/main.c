/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:57:19 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/21 16:34:47 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"


int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*forks;

	init_data(&data);
	if (!parse_input(argc, argv, &data))
		return (err(EARGS));
	forks = malloc((data.nb_of_philo) * sizeof(pthread_mutex_t));
	if (!forks)
		return (err(EUNKN), 1);
	data.philo = malloc((data.nb_of_philo) * sizeof(t_philo));
	if (!data.philo)
		return (err(EUNKN), 1);
	init_philo(&data, forks);
	if (!spawn_threads(&data))
		return (err(ETHRD));
	free(forks);
	return (0);
}