/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:10:28 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/24 18:03:50 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# define WALL '1'
# define FLOOR '0'
# define COLL 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef enum s_bool{
	false,
	true
} t_bool;

typedef struct s_position{
	int	x;
	int	y;
} t_position;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	*map;
} t_mlx;

typedef struct s_data{
	int	exit;
	int	start;
	int	collectible;
} t_data;

typedef struct  s_map{
	char		**map;
	int			moves;
	t_data		*data;
	t_position	*map_size;
	t_position	*exit;
	t_position	*player_pos;
	t_bool		is_valid;
} t_map;

#endif