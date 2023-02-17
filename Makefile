# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 21:52:28 by hkaddour          #+#    #+#              #
#    Updated: 2023/02/17 17:43:43 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAG = -Wall -Wextra -Werror -g
MLX = -lmlx -framework OpenGL -framework AppKit
LIB = libft/libft.a
#HEADER = include/cub3d.h
HEADER = $(addprefix include/, cub3d.h draw.h)
GNL = $(addprefix gnl/, gnl.c)
#PARSE = $(addprefix parsing/, parsing.c parsing_helper.c parsing_utils.c read_file.c)
#ERROR = $(addprefix error/, error_handling.c)
#FREE = $(addprefix free/, g_collector.c g_collector_utils.c)
#SRC = $(addprefix src/, main.c utils.c $(PARSE) $(ERROR) $(FREE))
SRC = $(addprefix src/, main.c utils.c parsing/read_file.c parsing/parse_file.c \
			error/error_handling.c free/g_collector.c parsing/color_converter.c \
			parsing/clr_texture_chk.c parsing/allocate_map.c parsing/parse_map.c \
			drawing/window_utils.c drawing/drawing.c drawing/images.c drawing/rays.c \
			drawing/dda_algorithm.c drawing/key_strokes.c drawing/math_utils.c \
			drawing/3d_projection.c)

OBJS = $(SRC:.c=.o)
GNL_OBJ = $(GNL:.c=.o)

BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPink=\033[1;38;5;205m
BRed=\033[1;31m
BPurple=\033[1;35m

all: $(NAME)

$(NAME): $(LIB) $(GNL_OBJ) $(OBJS)
	@echo ""
	@echo "$(BYellow)Merge $(BPurple)$(LIB) $(OBJS) $(GNL_OBJ) $(BYellow)output it in $(BPink)$(NAME)"
	@$(CC) $(LIB) $(OBJS) $(GNL_OBJ) $(MLX) -o $(NAME)

%.o: %.c $(HEADER) 
	@/bin/echo -n "."
	@$(CC) $(CFLAG) -c $< -o $@

$(LIB):
	@make -C ./libft

clean:
	@echo "$(BRed)clean"
	@make clean -C ./libft
	@rm -rf $(OBJS) $(GNL_OBJ)

fclean:
	@echo "$(BRed)fclean"
	@make fclean -C ./libft
	@rm -rf $(OBJS) $(GNL_OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean
