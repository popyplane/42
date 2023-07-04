# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 13:56:19 by bvieilhe          #+#    #+#              #
#    Updated: 2023/07/04 11:38:22 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex
BONUS		=	pipex_bonus

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LDFLAGS		=	-L./libft -lft

RM			=	rm
RMFLAG		=	-f

SRCS 		=	srcs/pipex.c \
				srcs/utils.c
OBJS 		=	${SRCS:.c=.o}

SRCS_B		= 	srcs/pipex_bonus.c \
				srcs/utils_bonus.c \
				srcs/utils.c
OBJS_B		=	${SRCS_B:.c=.o}

INCLUDES	=	-I./includes/

libft.a:
				make -C ./libft

all:			${NAME}

${NAME}:		libft.a ${OBJS}
				$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

bonus:			${BONUS}

${BONUS}:		libft.a ${OBJS_B}
				$(CC) $(CFLAGS) -o $@ $(OBJS_B) $(LDFLAGS)

%.o: %.c
				$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

clean:
				make -C ./libft clean
				${RM} ${RMFLAG} ${OBJS} ${OBJS_B}

fclean:			clean
				make -C ./libft fclean
				${RM} ${RMFLAG} ${NAME} ${BONUS}

re:				fclean all

re_bonus:		fclean bonus

.PHONY: all bonus clean fclean re re_bonus libft.a