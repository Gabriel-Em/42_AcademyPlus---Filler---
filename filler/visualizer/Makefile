# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/03 18:59:56 by gpop              #+#    #+#              #
#    Updated: 2018/06/13 02:39:58 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

SRC_DIR = ./srcs
INC_DIR = ./includes
LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/includes
MLX_DIR = ./minilibx_macos

FILES = main input_parser drawing map drawing_utils drawing_text
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
LIB_LINK = -L $(LIB_DIR) -lft
MLX_LINK = -L $(MLX_DIR) -lmlx 

SRC = $(patsubst %,$(SRC_DIR)/%.c,$(FILES))
OBJ = $(patsubst %,%.o,$(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@$(CC) -I $(LIB_INC) -I $(INC_DIR) -I $(MLX_DIR) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIB_LINK) $(MLX_LINK) $(MLXFLAGS) -o $(NAME) 
	
clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
