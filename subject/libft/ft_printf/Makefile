# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:18:24 by hyeondle          #+#    #+#              #
#    Updated: 2023/11/03 00:32:20 by Linsio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_printf.c\
			put_char.c\
			put_string.c\
			put_unsigned_int.c\
			put_void_pointer.c\
			utils.c\
			put_decimal.c\

INCD	= ./

GCC		= cc
CFLAG	=
LIB		= ar rcs

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

.c.o	:
			@${GCC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCD}

$(NAME)	:	${OBJS}
			@${LIB} $(NAME) ${OBJS}

all		:	$(NAME)

clean	:
			@${RM} ${OBJS}

fclean	:	clean
			@${RM} $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
