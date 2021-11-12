# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snadji-h <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:14:03 by snadji-h          #+#    #+#              #
#    Updated: 2021/11/12 14:02:34 by snadji-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_putchar.c ft_putstr.c ft_hex.c ft_hex_ptr.c ft_dec.c ft_udec.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc ${CFLAGS}

RM 			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

all:		${NAME}

bonus:		all

${NAME}:	${OBJS}
			ar cr ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
