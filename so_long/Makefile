# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 10:34:24 by bvieilhe          #+#    #+#              #
#    Updated: 2023/06/16 10:39:12 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	/srcs/so_long.c
INCLUDES	=	-I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
 
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)