/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:47 by codespace         #+#    #+#             */
/*   Updated: 2024/06/02 16:03:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
}	t_mlx;

typedef struct s_texture
{
	char	*east_wall;
	char	*west_wall;
	char	*north_wall;
	char	*south_wall;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_map
{
	char		**map;
	int			heigh;
	int			width;
	t_texture	*texture;
}	t_map;


#endif