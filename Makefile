# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 15:08:32 by abnaciri          #+#    #+#              #
#    Updated: 2024/05/01 19:32:01 by abnaciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar crs
SRC = pipex.c \
	utils.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strncmp.c \
	ft_putstr_fd.c \
	ft_put_error.c \

OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re