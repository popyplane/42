/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:30 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/12/21 17:12:20 by baptistevie      ###   ########.fr       */
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

// typedef struct s_var {
// 	char			*var_name;
// 	void			*value;
// 	struct s_var	*next;
// } t_var;

typedef enum s_bool {
	false,
	true
}	t_bool;

typedef enum e_token_type {
	T_STR,
	T_PIPE,
	T_AND,
	T_OR,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_APPEND_OUT,
	T_HEREDOC_IN,
	T_NL
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

// typedef struct s_io_info{
// 	int	redir_in;
// 	int	redir_out;
// 	int	append_mode;
// 	int	heredoc_mode;
// }	t_io_info;

// typedef struct s_buffer_info {
// 	int						simp_q_nb;
// 	int						doub_q_nb;
// 	t_io_info				io_info;
// 	struct s_buffer_info	*next;
// 	struct s_buffer_info	*prev;
// }	t_buffer_info;

/**
 *	FUNCTIONS
*/


#endif