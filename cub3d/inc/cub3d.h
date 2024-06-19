/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:56 by codespace         #+#    #+#             */
/*   Updated: 2024/06/19 17:26:17 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

/************* lib ******************/
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*********** minilibx ***************/
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/************* inc ******************/
# include "struct.h"
# include "define.h"


/**                 FUNCTIONS                   **/

/********** get_map.c **************/
t_map	*get_map(char *path);
t_map	*init_map(void);
void	get_map_dim(t_map *map, char *path);

/********** get_map_utils.c ********/
bool	is_texture_line(char *line);
bool	is_map_line(char *line);
void	get_texture_line(t_map *map, char *line);
void	get_map_line(t_map *map, char *line, int *row);

/************* error.c *************/
void    ft_error(char *msg);
void	*garbage_collector(void *ptr, bool clean);

/************* hooks.c *************/
int	handle_no_event(void *data);
int	handle_input(int keysym, t_mlx *data);
int	handle_keypress(int keysym, t_mlx *data);
int	handle_keyrelease(int keysym, void *data);

/************* img.c *************/
void	img_pix_put(t_img *img, int x, int y, int color);

/********** display_2d.c *************/
void	draw_tile(int x, int y, int color, t_game *data);
void	draw_map(t_game *data);


#endif