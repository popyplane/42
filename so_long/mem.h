/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:51:25 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/20 14:56:07 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
#define MEM_H

# include <stddef.h>

char	**ber_to_str(char *map);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *source, int value, size_t size);

#endif