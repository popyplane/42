/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:32:09 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:50:32 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minilibx-linux/mlx.h"
# include "display.h"
# include "error.h"
# include "strings.h"
# include "structs.h"
# include "free.h"
# include "hooks.h"
# include "utils.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SCORE_OFFSET 50

void	render_assets(t_mlx *mlx);
void	render_bg(t_mlx *mlx);
void	display_score(t_mlx *mlx);
int		ft_on_render(t_mlx *mlx);
void	init_window(t_mlx *mlx);

#endif