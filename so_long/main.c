/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:58:17 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/26 11:33:16 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "display.h"
#include "error.h"
#include "ft_split.h"
#include "print.h"
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
	t_mlx	*mlx;
	// char	**lst;
	// if (argc == 2)

	// lst = ft_split(argv[1], '.');
	// while (*lst)
	// {
	// 	ft_dprintf(1, "%s\n", *lst);
	// 	lst++;
	// }
	// return (0);

	if (argc != 2)
		ft_error(BAD_ARGS);
	mlx = ft_init(argv[1]);
	init_window(mlx);
	return (0);
	
}
