# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 11:52:44 by lsohler@stu       #+#    #+#              #
#    Updated: 2023/01/03 14:29:51 by lsohler@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRC_DIR		= srcs/
LIBFT_DIR	= libft/
INCLUDES	= includes
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
SRCS		= ft_atoi.c ft_isdigit.c ft_itoa.c ft_ps_check.c ft_ps_index.c ft_ps_main.c ft_ps_utils.c \
			ft_strcmp.c ft_swap.c ft_split.c \


all:
		$(CC) $(FLAGS) -I $(INCLUDES) $(SRCS) -o $(NAME)


clean:
		$(RM) $(OBJS)


fclean: 	clean
		$(RM) $(NAME)


re:		fclean all

.PHONY: all clean fclean re