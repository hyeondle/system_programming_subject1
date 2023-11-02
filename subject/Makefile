# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 22:10:00 by Linsio            #+#    #+#              #
#    Updated: 2023/11/02 22:15:12 by Linsio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	myeditor

HEADER_DIR	=	./includes/
HEADER		=	headers.h\
				myeditor.h\
				structs.h\

SOURCE_DIR	=	./sources/

SOURCES		=	main.c\
				init.c\
				operation.c\
				print.c\
				edit.c\
				utils.c\
				utils2.c\

SOURCE		=	$(addprefix $(SOURCE_DIR), $(SOURCES))
OBJECT		=	$(SOURCE:.c=.o)\

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_FLAG	=	-L$(LIBFT_DIR) -lft

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
RM_OBJECT	=	rm -rf $(OBJECT)

.c.o		:
				$(CC) $(FLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

all			:	$(NAME)

$(LIBFT)	:
				@make -C $(LIBFT_DIR)

$(NAME)		:	$(OBJECT) $(LIBFT)
				$(CC) $(FLAGS) -I $(HEADER_DIR) $(OBJECT) $(LIBFT_FLAG) -o $(NAME)

clean		:
				$(RM_OBJECT)
				@make -C $(LIBFT_DIR) clean

fclean		:	clean
				rm -rf $(NAME)
				@make -C $(LIBFT_DIR) fclean

re			:
				@make fclean
				@make all

.PHONY		:	all clean fclean re
