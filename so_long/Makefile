# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 10:34:24 by bvieilhe          #+#    #+#              #
#    Updated: 2023/07/26 10:19:21 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	display.c \
				error.c \
				free.c \
				ft_split.c \
				hooks.c \
				main.c \
				map.c \
				map2.c \
				mem.c \
				print.c \
				strings.c \
				texture.c \
				utils.c

INCLUDES	=	-Imlx \
				-I.

OBJS 		=	${SRCS:.c=.o}

RM			=	rm
RMFLAG		=	-f

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3
MLX_FLAGS	=	-L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
 
%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

 
all:			${NAME} minilibx

minilibx:
	make -C ./minilibx-linux

$(NAME):		minilibx $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:				
	${RM} ${RMFLAG} ${OBJS}

fclean:			clean
	${RM} ${RMFLAG} ${NAME}

re:				fclean all

.PHONY: all clean fclean re 