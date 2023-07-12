/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:10:28 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/12 14:12:01 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef enum s_bool{
	false,
	true
} t_bool;

typedef struct s_position{
	int	x;
	int	y;
} t_position;

typedef struct s_data{
	int	exit;
	int	start;
	int	collectible;
} t_data;

typedef struct  s_map{
	char		**map;
	t_data		*data;
	t_position	*map_size;
	t_position	*exit;
	t_position	*player_pos;
	t_bool		is_valid;
} t_map;

#endif