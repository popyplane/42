/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:26:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/07/12 15:03:47 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int render_2d(t_game *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img.mlx_img, 0, 0);
	return (0);
}
