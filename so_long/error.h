/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:49 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:52:19 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EXCESS_P "MAP NOT VALID : There is too many players (P)"
# define NO_P "MAP NOT VALID : No player (P) found"
# define EXCESS_E "MAP NOT VALID : There is too many exit (E)"
# define NO_E "MAP NOT VALID : No exit (E) found"
# define NO_C "MAP NOT VALID : No colllectible (C) found"
# define SIDEWALL "MAP NOT VALID : Every side of the map have to be walls (1)"
# define RCTGL "MAP NOT VALID : Map needs to have as much char on each line"
# define MALLOC_FAILURE "MALLOC FAILURE : Last memory allocation failed"
# define REACH "MAP NOT VALID : Ensure exit and collectible(s) to be reachable"
# define UNK_DATA "MAP NOT VALID : The map should only get either P E C 0 1"
# define EX11 "X11 error"
# define OPEN "FILE OPENING ERROR : Ensure the map location inside /maps"
# define ETXTUR "Texture error"
# define BAD_ARGS "BAD ARGUMENTS : Only the map name is necessary"

void	ft_error(char *msg);

#endif