# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 10:46:47 by aziabkin          #+#    #+#              #
#    Updated: 2018/08/08 15:36:23 by aziabkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

LIB_DIR := ./libft/
SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/

SRC :=	main.c\
		window.c\
		hooks.c\
		read_valid.c\
		freesher.c\
		draw.c\
		realization.c\
		textures.c\
		walls_color.c\
		controls.c\
		checker.c\
		color_fc.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC := gcc
FLAGS := -Wall -Wextra -Werror

FRMWR := -framework OpenGL -framework AppKit
MLX_LIB := -L /usr/local/lib/ -lmlx

LIBFT = $(LIB_DIR)libft.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)incs

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR) -I /usr/locale/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT) $(FRMWR) $(MLX_LIB)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all
