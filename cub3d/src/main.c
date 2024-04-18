/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:50 by codespace         #+#    #+#             */
/*   Updated: 2024/04/18 12:56:15 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/includes.h"
#include "mlx.h"

int main()
{
    void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
    if (!mlx)
        return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
    
    return (0);
}