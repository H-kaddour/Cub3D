# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 21:52:28 by hkaddour          #+#    #+#              #
#    Updated: 2023/02/24 17:42:23 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAG = -Wall -Wextra -Werror -g
MLX = -lmlx -framework OpenGL -framework AppKit
MLX_LIB = minilibx/libmlx.a
LIB = libft/libft.a
HEADER = $(addprefix include/, cub3d.h draw.h)
GNL = $(addprefix gnl/, gnl.c)
SRC = $(addprefix mandatory/, main.c utils.c parsing/read_file.c parsing/parse_file.c \
			error/error_handling.c free/g_collector.c parsing/color_converter.c \
			parsing/clr_texture_chk.c parsing/allocate_map.c parsing/parse_map.c \
			drawing/window_utils.c drawing/drawing.c drawing/images.c drawing/rays.c \
			drawing/key_strokes.c drawing/math_utils.c drawing/3d_projection.c \
			drawing/texture.c drawing/key_strokes_helper.c drawing/sight.c \
			parsing/clr_texture_chk_helper.c drawing/rays_distance.c \
			drawing/rays_intersection.c)

SRC_BONUS = $(addprefix bonus/, main.c utils.c parsing/read_file.c parsing/parse_file.c \
			error/error_handling.c free/g_collector.c parsing/color_converter.c \
			parsing/clr_texture_chk.c parsing/allocate_map.c parsing/parse_map.c \
			drawing/window_utils.c drawing/drawing.c drawing/images.c drawing/rays.c \
			drawing/key_strokes.c drawing/math_utils.c drawing/3d_projection.c \
			drawing/texture.c drawing/key_strokes_helper.c drawing/sight.c \
			parsing/clr_texture_chk_helper.c drawing/rays_distance.c \
			drawing/rays_intersection.c drawing/mini_map.c drawing/dda_algorithm.c)

GNL_OBJ = $(GNL:.c=.o)
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPink=\033[1;38;5;205m
BRed=\033[1;31m
BPurple=\033[1;35m

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIB) $(GNL_OBJ) $(OBJS)
	@echo ""
	@echo "$(BYellow)Merge $(BPurple)$(LIB) $(OBJS) $(GNL_OBJ) $(BYellow)output it in $(BPink)$(NAME)"
	@$(CC) $(MLX_LIB) $(LIB) $(OBJS) $(GNL_OBJ) $(MLX) -o $(NAME)

bonus: $(MLX_LIB) $(LIB) $(GNL_OBJ) $(OBJS_BONUS)
	@echo ""
	@echo "$(BYellow)Merge the bonus code"
	@$(CC) $(MLX_LIB) $(LIB) $(OBJS_BONUS) $(GNL_OBJ) $(MLX) -o $(NAME_BONUS)

%.o: %.c $(HEADER) 
	@/bin/echo -n "."
	@$(CC) $(CFLAG) -c $< -o $@

$(MLX_LIB):
	@make -C ./minilibx

$(LIB):
	@make -C ./libft

clean:
	@echo "$(BRed)clean"
	@make clean -C ./libft
	@make clean -C ./minilibx
	@rm -rf $(OBJS) $(OBJS_BONUS) $(GNL_OBJ)

fclean:
	@echo "$(BRed)fclean"
	@make fclean -C ./libft
	@make clean -C ./minilibx
	@rm -rf $(OBJS) $(OBJS_BONUS) $(GNL_OBJ) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean
