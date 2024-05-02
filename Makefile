# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:45:19 by agheredi          #+#    #+#              #
#    Updated: 2024/05/02 11:56:32 by agheredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FLAGS = -Wall -Werror -Wextra -g #-fsanitize='address,undefined'
SRC = src/main.c

CC = gcc
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OPENGL -framework AppKit
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
HEADER = include/cub3d.h

# Objects
OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

# Colors
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
DEFAULT = \033[0m

all: subsystems $(NAME)

# General rule for files in srcs/
$(OBJ_DIR)/%.o: src/%.c $(HEADER) Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_DIR) 
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"
	

re: fclean all

.PHONY: all re clean fclean subsystems
