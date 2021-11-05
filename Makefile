# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:14:03 by snadji-h          #+#    #+#              #
#    Updated: 2021/11/05 18:51:49 by snadji-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_putchar.c ft_putstr.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc ${CFLAGS}

RM 			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

all:		${NAME}

${NAME}:	${OBJS}
			ar cr ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
