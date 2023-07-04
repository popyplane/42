# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 10:34:24 by bvieilhe          #+#    #+#              #
#    Updated: 2023/06/16 11:56:11 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	srcs/so_long.c
INCLUDES	=	-Iincludes -Imlx

OBJS 		=	${SRCS:.c=.o}

RM			=	rm
RMFLAG		=	-f

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LDFLAGS		=	-L./libft -lft
MLX_FLAGS	=	-L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
 
%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

 
all:			${NAME} minilibx

libft:
	make -C ./libft

minilibx:
	make -C ./minilibx-linux

$(NAME):		libft minilibx $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	make -C ./libft clean				
	${RM} ${RMFLAG} ${OBJS}

fclean:			clean
	make -C ./libft fclean
	${RM} ${RMFLAG} ${NAME}

re:				fclean all

.PHONY: all clean fclean re libft.a