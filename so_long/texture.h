/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:29:57 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/28 13:51:25 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEXTURES_H
# define TEXTURES_H

# include "structs.h"

# define TILE_SIZE 48

# define FLOOR_PATH "./assets/floor.xpm"
# define WALL_PATH "./assets/wall.xpm"
# define PLAYER_PATH "./assets/player.xpm"
# define COLLECTIBLE_PATH "./assets/collectible.xpm"
# define EXIT_PATH "./assets/exit.xpm"

t_bool	load_textures(t_mlx *mlx);
void	malloc_pos(t_map *map);
t_data	*init_data(void);


#endif 