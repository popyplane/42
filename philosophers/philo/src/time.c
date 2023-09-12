/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:24:22 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/09/12 17:25:42 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes.h>

unsigned long	ft_get_time_in_ms(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	ft_get_time_diff(unsigned long time)
{
	unsigned long	current_time;

	current_time = ft_get_time_in_ms();
	return ((int)(current_time - time));
}

int	ft_get_rounded_time_diff(unsigned long time, int round)
{
	unsigned long	current_time;

	current_time = ft_get_time_in_ms();
	return ((int)(current_time - time) - ((int)(current_time - time) % round));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	start_time;

	start_time = ft_get_time_in_ms();
	while ((unsigned long)ft_get_time_diff(start_time) < time)
		usleep(100);
}
