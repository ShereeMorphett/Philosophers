# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:37:37 by smorphet          #+#    #+#              #
#    Updated: 2023/07/13 09:03:59 by smorphet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c input_validation.c utilities.c initialization.c routine.c \
	monitoring.c

OBJ = $(SRC:.c=.o)
INC := philosophers.h

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(OBJ): %.o: %.c $(INC)
	$(CC) -c $(FLAGS) -I. $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "\033[0;92m* $(NAME) was created *\033[0m"

clean:
	rm -rf $(OBJ)
	@echo "\033[0;91m* $(NAME) .o files were deleted *\033[0m"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re: fclean all

.PHONY: start all clean fclean re

.SILENT:

