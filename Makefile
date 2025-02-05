# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 13:21:40 by alfavre           #+#    #+#              #
#    Updated: 2025/02/05 11:50:26 by alfavre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#							Check environnement								#
#############################################################################
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

#############################################################################
#								Variables									#
#############################################################################
NAME = so_long
LIBFT = ./libft/libft.a
SRC_DIR = src/
OBJ_DIR = obj/
INC = -Iinclude -Ilibft -Imlx
LIB = -Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm -lbsd
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
#############################################################################
#									Sources									#
#############################################################################
SRC_FILES = main \
			events \
			map map_utils check_map validate_map \
			movement \
			clean \
			render

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#############################################################################
#									Rules									#
#############################################################################
OBJF = .cache_exists

all: $(MLX_LIB) $(LIBFT) $(OBJF) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "Compiling $<"
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

$(MLX_LIB):
	@echo " [ .. ] | Compiling mlx.."
	make -C $(MLX_DIR)
	@echo " [ OK ] | mlx ready!"

$(LIBFT):
	@echo " [ .. ] | Compiling libft.."
	make -C libft
	@echo " [ OK ] | Libft ready!"

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	make $@ -C libft
	make $@ -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)
	@echo "object files removed."

fclean: clean
	make $@ -C libft
	rm -rf $(NAME)
	@echo "binary file removed."

re: fclean all

.PHONY: all clean fclean re