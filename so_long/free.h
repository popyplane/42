/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:45:10 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/25 16:25:46 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
#define FREE_H

void	free_array(void	**array);
void	free_mlx(t_mlx *mlx);
void	free_map(t_map *map);

#endif