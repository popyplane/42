/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:25 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/28 14:48:34 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

# define TILE_SIZE 48

# include "texture.h"

char	**ber_to_str(char *map);
char	*ft_itoa(int nbr);
void	free_init_err(t_mlx *mlx, char *err);
int    print_map(char **map, int size);
void init_map_bases(t_map *map);


#endif