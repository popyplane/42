# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 10:59:14 by bvieilhe          #+#    #+#              #
#    Updated: 2023/05/15 12:04:38 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

RM = rm
RMFLAG = -f

SRCS = \
		sources/instructions.c \
		sources/lists.c \
		sources/push_swap.c \
		sources/sort.c \
		sources/utils.c \
		includes/ft_printf/ft_intlen.c \
		includes/ft_printf/ft_printf.c \
		includes/ft_printf/ft_putchar_fd.c \
		includes/ft_printf/ft_puthex_fd.c \
		includes/ft_printf/ft_puthex_up_fd.c \
		includes/ft_printf/ft_putnbr_base_fd.c \
		includes/ft_printf/ft_putnbr_fd.c \
		includes/ft_printf/ft_putptr_fd.c \
		includes/ft_printf/ft_putstr_fd.c \
		includes/ft_printf/ft_putunbr_fd.c \
		includes/ft_printf/ft_strchr.c \
		includes/ft_printf/ft_strlen.c

INCLUDES = includes/push_swap.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(RMFLAG) $(OBJS)


fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean run fclean re 
