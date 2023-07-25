/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:58:17 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 17:26:00 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "error.h"
#include "map.h"

t_mlx   *ft_init(char *map_name)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_error(MALLOC_FAILURE);
	mlx->map = init_map(map_name);
	return (mlx);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		ft_error(BAD_ARGS);
	data = ft_init(argv[1]);
	ft_init_window(data);
	return (0);
}
