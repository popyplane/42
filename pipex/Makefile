# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 13:56:19 by bvieilhe          #+#    #+#              #
#    Updated: 2023/05/29 14:35:25 by bvieilhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex

SRCS 		=	srcs/pipex.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c
OBJS 		=	${SRCS:.c=.o}
HEADER 		=	-Iincludes

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

.c.o:			%.o : %.c
								${CC} ${CFLAGS} ${HEADER} -c $(<:.c=.o)

all:			${NAME}

${NAME}:		${OBJS}
								@echo "\033[33m----Compiling lib----"
								@make re -C ./libft
								@$(CC) ${OBJS} -Llibft -lft -o ${NAME}
								@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
								@make clean -C ./libft
								@rm -f ${OBJS}

fclean:			clean
								@make fclean -C ./libft
								@rm -f ${NAME}
								@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:				fclean all

party:
								@printf "\033c"
								@echo "\n\033[35m♪┏(・o･)┛♪"
								@sleep 1
								@printf "\033c"
								@echo "\033[1;33m♪┗(・o･)┓♪"
								@sleep 1
								@printf "\033c"
								@echo "\n\033[36m♪┏(・o･)┛♪"
								@sleep 1
								@printf "\033c"
								@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re re_bonus bonus party