# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 15:17:47 by codespace         #+#    #+#              #
#    Updated: 2024/04/18 12:55:52 by baptistevie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
B_NAME		=	cub3D_bonus

CFLAGS		=	#-Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx -Ilibft
else
	INCLUDES = -I/opt/X11/include -Imlx -Ilibft
endif

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

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
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

all			:	$(NAME)

# $(NAME)		:	CFLAGS += -Iinc
$(NAME)		:	$(OBJS)
				@make -C libft/
				@make -C mlx/
				@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
				@$(CC) $(CFLAGS) $(MLX_FLAGS) -Llibft -lft $(OBJS) -o $(NAME)
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