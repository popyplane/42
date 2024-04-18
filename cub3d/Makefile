# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 15:17:47 by codespace         #+#    #+#              #
#    Updated: 2024/04/18 09:29:47 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
B_NAME		=	cub3D_bonus

CFLAGS		=	-Wall -Wextra -Werror -Ilibft -Imlx
MXFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit
CC			=	cc
RM			=	rm -rf

NONE		=	'\033[0m'
RED			=	'\033[0;31m'
GREEN		=	'\033[32m'
GRAY		=	'\033[2;37m'
ITALIC		=	'\033[3m'

# -------------------------------- MANDATORY --------------------------------- #

_LIBCUB		=	
LIBCUB		=	$(addprefix libcub/, $(_LIBCUB))

_UTILS		=	
UTILS		=	$(addprefix utils/, $(_UTILS))

_PARSING	=	
PARSING		=	$(addprefix parsing/, $(_PARSING))

_RENDERING	=	
RENDERING	=	$(addprefix rendering/, $(_RENDERING))

_SRCS		=	$(LIBCUB) $(UTILS) $(PARSING) $(RENDERING)
SRCS		=	$(addprefix src/, $(_SRCS)) src/main.c
OBJS		=	$(SRCS:.c=.o)

# -------------------------------- RECIPE ------------------------------------ #

.c.o		:
				@echo $(ITALIC)$(GRAY) "     - Making $<..." $(NONE)
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all			:	$(NAME)

$(NAME)		:	CFLAGS += -Iinc
$(NAME)		:	$(OBJS)
				@make -C libft/
				@make -C mlx/
				@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
				@$(CC) $(CFLAGS) $(MXFLAGS) -Llibft -lft $(OBJS) -o $(NAME)
				@echo $(GREEN)"- Compiled -"$(NONE)

clean		:
				@echo $(ITALIC)$(GRAY) "     - Removing object files..." $(NONE)
				@$(RM) $(OBJS) $(B_OBJS)
				@make clean -C libft/
				@make clean -C mlx/

fclean		:	clean
				@echo $(ITALIC)$(GRAY) "     - Removing $(NAME)..." $(NONE)
				@$(RM) $(NAME) $(B_NAME)
				@make fclean -C libft/
				@make fclean -C mlx/

re			:	fclean all

.PHONY		:	all clean fclean re