/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:49 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/07/24 16:34:45 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

# define EXCESS_P "MAP NOT VALID : There is too many players (P)"
# define NO_P "MAP NOT VALID : No player (P) found"
# define EXCESS_E "MAP NOT VALID : There is too many exit (P)"
# define NO_E "MAP NOT VALID : No exit (E) found"
# define NO_C "MAP NOT VALID : No colllectible (C) found"
# define RCTGL "MAP NOT VALID : Map needs to have as much char on each line"
# define MALLOC_FAILURE "MALLOC FAILURE : Last memory allocation failed"
# define REACH "MAP NOT VALID : Ensure exit and collectible(s) to be reachable"
# define UNK_DATA "MAP NOT VALID : The .ber map should only contains either (P), (E), (C), (0) or (1)"

void	ft_error(char *msg);

#endif