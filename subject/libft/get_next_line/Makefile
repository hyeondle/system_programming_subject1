# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 16:19:46 by hyeondle          #+#    #+#              #
#    Updated: 2023/11/02 22:11:44 by Linsio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libftgetnextline.a

SRCS	=	get_next_line.c\
			get_next_line_utils.c\
			
INCD	= ./

GCC		= cc
CFLAG	= -Wall -Wextra -Werror
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
