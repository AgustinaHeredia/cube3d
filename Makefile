# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:45:19 by agheredi          #+#    #+#              #
#    Updated: 2024/06/02 11:57:25 by agheredi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
FLAGS = -Wall -Werror -Wextra -g #-fsanitize='address,undefined'
SRC = src/main.c \
		src/check_arg.c \
		src/error.c \
		src/init_game.c \
		src/key_press.c \
		src/exit.c \
		src/check_map.c \
		src/check_resolt.c \
		src/utils_map.c \
		src/check_path.c \
		src/check_color.c \
		src/paint_map2d.c \
		src/utils_keys.c \
		src/path_utils.c \
		src/utils_player.c \
		src/raycast.c \
		src/init_raycast.c \
		src/raycast_utils.c \
		src/texture_utils.c \
		src/utils_rotate.c \

SRCS_BONUS = bonus/main_bonus.c \
				bonus/check_arg_bonus.c \
				bonus/error_bonus.c \
				bonus/init_game_bonus.c \
				bonus/key_press_bonus.c \
				bonus/exit_bonus.c \
				bonus/check_map_bonus.c \
				bonus/check_resolt_bonus.c \
				bonus/utils_map_bonus.c \
				bonus/check_path_bonus.c \
				bonus/check_color_bonus.c \
				bonus/paint_map2d_bonus.c \
				bonus/utils_keys_bonus.c \
				bonus/path_utils_bonus.c \
				bonus/utils_player_bonus.c \
				bonus/raycast_bonus.c \
				bonus/init_raycast_bonus.c \
				bonus/raycast_utils_bonus.c \
				bonus/texture_utils_bonus.c \
				bonus/utils_rotate_bonus.c \

CC = gcc
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
HEADER = include/cub3d.h
HEADER_BONUS = include/cub3d_bonus.h

# Objects
OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
OBJS_DIR_BONUS = obj_bonus
OBJECTS_BONUS = $(addprefix $(OBJS_DIR_BONUS)/,$(notdir $(SRCS_BONUS:.c=.o)))

# Colors
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
DEFAULT = \033[0m

all: subsystems $(NAME)

# General rule for files in src/
$(OBJ_DIR)/%.o: src/%.c $(HEADER) Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -Imlx -c -o $@ $<

$(OBJS_DIR_BONUS)/%.o: bonus/%.c $(HEADER_BONUS) Makefile
	@mkdir -p $(OBJS_DIR_BONUS)
	@$(CC) $(FLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all --no-print-directory
	@make -C $(LIBFT_PATH) all --no-print-directory

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean: clean_bonus
	@make -C $(MLX_PATH) clean --no-print-directory
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

clean_bonus:
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@rm -rf $(OBJS_DIR_BONUS)
	@rm -f .bonus_built
	@echo -e "$(YELLOW)bonus object files deleted!$(DEFAULT)"

fclean: clean
	@make -C $(MLX_PATH) fclean --no-print-directory
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f .bonus_built
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

bonus: $(HEADER_BONUS) $(OBJECTS_BONUS) subsystems .bonus_built

.bonus_built: $(OBJECTS_BONUS)
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJECTS_BONUS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME_BONUS)
	@touch .bonus_built
	@echo -e "$(GREEN)$(NAME_BONUS) (bonus) created!$(DEFAULT)"

.PHONY: all re clean fclean subsystems bonus clean_bonus
.SILENT:
