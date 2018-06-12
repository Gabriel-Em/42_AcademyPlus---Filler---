# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/03 18:59:56 by gpop              #+#    #+#              #
#    Updated: 2018/06/03 19:49:31 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC_DIR = ./srcs
INC_DIR = ./includes
LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/includes

FILES = main input_parser map piece output_parser score_calculator
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_LINK = -L $(LIB_DIR) -lft

SRC = $(patsubst %,$(SRC_DIR)/%.c,$(FILES))
OBJ = $(patsubst %,%.o,$(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@$(CC) -I $(LIB_INC) -I $(INC_DIR) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
