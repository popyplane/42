/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:30 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/10/17 16:50:12 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

/**
 *	LIBRARIES
*/

/**
 *	STRUCTURES
*/

typedef enum s_bool {
	false,
	true
}	t_bool;

typedef enum e_token_type {
	T_CMD,
	T_PIPE,
	T_AND,
	T_OR,
	T_IO_MODIFIER,
	T_FILE,
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

/**
 *	FUNCTIONS
*/


#endif