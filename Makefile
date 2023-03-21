# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jporta <jporta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 14:59:15 by mcordoba          #+#    #+#              #
#    Updated: 2023/03/21 14:58:40 by jporta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = 		main.c \
				main_utils/errmanag.c \
				main_utils/file_manager.c \
				main_utils/freedom.c

SRC_PARSER =	parser/parser.c \
				parser/utils/read_file.c \
				parser/utils/data_assigner.c \
				parser/utils/assigner_checkers.c \
				parser/utils/parser_err_msg.c

SRC_RAYCAST =	raycast/raycast.c

NAME = cub3d

SEARCH = cub3d.h

OBJ_MAIN = $(SRC_MAIN:%.c=%.o)

OBJ_PARSER = $(SRC_PARSER:%.c=%.o)

OBJ_RAYCAST = $(SRC_RAYCAST:%.c=%.o)

RM = rm -f

CC = gcc

CFLAGS = -I. -g3 -Wall -Werror -Wextra -Imlx

CFNAME = -o $(NAME)

LIBFT_SRC = libs/libft/libft.a

# MINILIBX_SRC = libs/mlx_setup/libmlx.a

all: $(NAME)

#### MACOS COMPILER WITH LIBRARIES $(MINILIBX_SRC)

$(NAME): $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(SEARCH)
	@make -C libs/libft
	@make -C libs/mlx_setup
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(LIBFT_SRC) -lmlx -framework OpenGL -framework AppKit -L . $(CFNAME)

clean:
	@make clean -C libs/libft
	@make clean -C libs/mlx_setup
	$(RM) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f libs/libft/libft.a
	# @rm -f libs/mlx_setup/libmlx.a
	$(RM) $(NAME) $(OBJ)

#### LINUX PARSER



# $(NAME): $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(SEARCH)
# 	@make -C libs/libft
# 	$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST) $(LIBFT_SRC) -L. $(CFNAME)

# clean:
# 	@make clean -C libs/libft
# 	$(RM) $(OBJ_MAIN) $(OBJ_PARSER) $(OBJ_RAYCAST)

# fclean: clean
# 	rm -f libs/libft/libft.a
# 	$(RM) $(NAME) $(OBJ)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
