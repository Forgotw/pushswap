# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 11:52:44 by lsohler@stu       #+#    #+#              #
#    Updated: 2023/04/14 12:26:12 by lsohler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJET #
NAME = push_swap
BONUS = checker

# HEADER #
INCLUDES = includes/
HEADER_SRCS = push_swap.h
HEADER = $(addprefix $(INCLUDES), $(HEADER_SRCS))

# SOURCES #
SRCS = ft_ps_check.c ft_ps_data.c ft_ps_free.c ft_ps_index.c main.c ft_ps_pre_sort.c ft_ps_utils.c ft_push.c ft_r_rotate.c ft_rotate.c ft_swap.c post_sort.c post_sort2.c move.c
LIBFT_DIR = libft/
LIBFT_FUNC = ft_atoi.c ft_isdigit.c ft_itoa.c ft_split.c ft_strcmp.c ft_abs.c 
LIBFT_SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_FUNC))
OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
GNL_FUNC = get_next_line.c get_next_line_utils.c
GNL_DIR = gnl/
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_FUNC))
GNL_OBJS = $(GNL_SRCS:.c=.o)
BONUS_SRCS = checker.c checker_op.c ft_ps_check.c ft_ps_data.c ft_ps_free.c ft_ps_index.c ft_ps_pre_sort.c ft_ps_utils.c ft_push.c ft_r_rotate.c ft_rotate.c ft_swap.c post_sort.c post_sort2.c move.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# UTILS #
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

# COLORS #
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

# COMMANDS #
%.o: %.c
				@$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS) $(LIBFT_OBJS)
				@$(CC) $(FLAGS) -I $(INCLUDES) $(OBJS) $(LIBFT_OBJS) -o $(NAME)
				@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"


all: $(NAME)

bonus: $(LIBFT_OBJS) $(BONUS_OBJS) $(GNL_OBJS)
				@$(CC) $(FLAGS) -I $(INCLUDES) $(LIBFT_OBJS) $(BONUS_OBJS) $(GNL_OBJS) -o $(BONUS)
				@echo "$(BONUS)$(NAME) compiled!$(DEFAULT)"

clean:
				@$(RM) $(OBJS)
				@$(RM) $(LIBFT_OBJS)
				@$(RM) $(BONUS_OBJS)
				@echo "$(YELLOW)object files cleaned!$(DEFAULT)"

fclean: clean
				@$(RM) $(NAME)
				@$(RM) $(BONUS)
				@echo "$(RED)$(NAME) cleaned!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re