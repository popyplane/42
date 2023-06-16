# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 13:56:19 by bvieilhe          #+#    #+#              #
#    Updated: 2023/06/06 15:56:49 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LDFLAGS		=	-L./libft -lft

RM			=	rm
RMFLAG		=	-f

SRCS 		=	srcs/pipex.c \
				srcs/utils.c
INCLUDES	=	-I./includes/

OBJS 		=	${SRCS:.c=.o}

all:			${NAME}

libft.a:
				make -C ./libft

${NAME}:		libft.a ${OBJS}
				$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
				$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@								

clean:
				make -C ./libft clean				
				${RM} ${RMFLAG} ${OBJS}

fclean:			clean
				make -C ./libft fclean
				${RM} ${RMFLAG} ${NAME}

re:				fclean all

.PHONY: all clean fclean re libft.a