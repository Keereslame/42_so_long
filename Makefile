# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 13:21:40 by alfavre           #+#    #+#              #
#    Updated: 2025/01/28 13:23:06 by alfavre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#								Variables									#
#############################################################################
NAME = so_long
LIBFT = ./libft
MINI_LIBX = ./minilibx-linux
SRC_DIR = src/
OBJ_DIR = obj/
CFLAGS = -g -Wall -Wextra -Werror -Iinclude

#############################################################################
#									Sources									#
#############################################################################
SRC_FILES = main \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#############################################################################
#									Rules									#
#############################################################################
OBJF = .cache_exists

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	@echo "so_long compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "Compiling $<"
	cc $(CFLAGS) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re