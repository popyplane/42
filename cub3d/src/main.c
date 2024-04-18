/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/16 13:00:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/includes.h"

int main()
{
    t_mlx   *mlx = 0;

    mlx->mlx_ptr = mlx_init();
    mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 100, "test");
    return (0);
}