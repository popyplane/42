/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:30 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/10/21 15:43:47 by baptistevie      ###   ########.fr       */
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
typedef struct s_var {
	char			*var_name;
	void			*value;
	struct s_var	*next;
} t_var;

typedef enum s_bool {
	false,
	true
}	t_bool;

typedef enum e_token_type {
	T_CMD,
	T_PIPE,
	// T_AND,
	// T_OR,
	T_IO_MODIFIER
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_IO_info{
	t_bool	redir_in;
	t_bool	redir_out;
	t_bool	append_mode;
	t_bool	heredoc_mode;
}	t_io_info;

typedef struct s_buffer_info {
	int			simp_q_nb;
	int			doub_q_nb;
	int			pipe_nb;
	t_io_info	io_info
}	t_buffer_info;

/**
 *	FUNCTIONS
*/


#endif