# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 12:45:26 by codespace         #+#    #+#              #
#    Updated: 2024/06/02 15:27:15 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		cub3D

SRCS_FILES	=	get_map.c \
				get_map_utils.c \
				main.c

INC_FILES	= cub3d.h

SRCS	=	$(addprefix src/, $(SRCS_FILES))

INCS	=	$(addprefix inc/, $(INC_FILES))

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I./inc -g3

INCLUDES	= -I. -Imlx/.

LIB		= -Lmlx -lmlx -lXext -lX11 -Llibft -lft -lm

OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

OBJS	=		$(addprefix objs/, $(OBJS_FILES))

DEP		=		$(OBJS:%.o=%.d)

all		:		$(NAME)

$(NAME)	:	$(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

clean	:
	make -C libft fclean
	make -C mlx clean
	rm -rf $(OBJS) $(DEP)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

objs/%.o	: src/%.c $(INCS)
	mkdir -p objs
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re