/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:45:47 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 17:05:17 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
#define HOOKS_H

# include <X11/keysym.h>
# include "free.h"
# include "structs.h"
# include "minilibx-linux/mlx.h"

void	ft_handle_move(int keysym, t_mlx *mlx);
int		ft_on_keypress(int keysym, t_mlx *mlx);
int		ft_on_close(t_mlx *mlx);

#endif