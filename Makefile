# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/07/12 01:38:16 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

TESTMAP = estupid.ber

SRC = src/main.c \
	src/errors/register.c \
	src/mlx/color.c \
	src/map/init.c \
	src/map/parse.c \
	src/map/destroy.c \
	src/map/validation/is_valid.c \
	src/map/validation/check_emptiness.c \
	src/map/validation/check_filename.c \
	src/map/validation/check_map_chars.c \
	src/map/validation/check_spawn.c \
	src/map/validation/check_metadata.c \

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

CC = gcc

LIBFT_DIR = libft
MLX_DIR = minilibx-linux

CFLAGS = -Wall -Wextra -Werror -MMD -g3 \
			-I . \
			-I inc/ \
			-I $(LIBFT_DIR) \
			-I $(MLX_DIR)\

LDFLAGS = -L $(LIBFT_DIR) -lft \
			-L $(MLX_DIR) -lmlx \
			-L /usr/lib -lXext -lX11 -lm -lz \

LDLIBS = -lft

all: libft mlx $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

libft:
	make --no-print-directory -C $(LIBFT_DIR)

mlx:
	make --no-print-directory -C $(MLX_DIR)

clean:
	make --no-print-directory -C $(LIBFT_DIR) clean
	make --no-print-directory -C $(MLX_DIR) clean
	rm -f $(OBJ) $(DEPS)

fclean: clean
	make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

rt: fclean test

n:
	norminette inc src libft

t:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes \
	./cub3d map/$(m).ber

test: all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes \
	./cub3d map/$(TESTMAP)

test_failure: all
	chmod -r map/fail/fail-read-rights.cub && \
	echo "\033[0;32m.cub file\033[0m" && ./cub3d map/fail/.cub || \
	echo "\033[0;32mnon existing file\033[0m" && ./cub3d map/fail/idontexist.cub || \
	echo "\033[0;32mduplicate spawn\033[0m" && ./cub3d map/fail/fail-duplicate-spawn.cub || \
	echo "\033[0;32mempty map\033[0m" && ./cub3d map/fail/fail-empty.cub || \
	echo "\033[0;32mwrong extension\033[0m" && ./cub3d map/fail/fail-extension.cu || \
	echo "\033[0;32mno spawn\033[0m" && ./cub3d map/fail/fail-lacks-spawn.cub || \
	echo "\033[0;32mno read rights\033[0m" && ./cub3d map/fail/fail-read-rights.cub || \
	echo "\033[0;32munknown char\033[0m" && ./cub3d map/fail/fail-unknown-char.cub || \
	echo "\033[0;32mcolor negative\033[0m" && ./cub3d map/fail/fail-color-negative.cub || \
	echo "\033[0;32mcolor too high\033[0m" && ./cub3d map/fail/fail-color-too-high.cub || \
	echo "\033[0;32mcolor missing\033[0m" && ./cub3d map/fail/fail-color-missing.cub || \
	echo "\033[0;32mcolor format (1 block)\033[0m" && ./cub3d map/fail/fail-color-format.cub || \
	echo "\033[0;32mcolor format (> 2 blocks)\033[0m" && ./cub3d map/fail/fail-color-format-2.cub || \
	echo "\033[0;32mtexture missing\033[0m" && ./cub3d map/fail/fail-texture-missing.cub || \
	echo "\033[0;32mtexture format (1 block)\033[0m" && ./cub3d map/fail/fail-texture-format.cub || \
	echo "\033[0;32mtexture format (> 2 blocks)\033[0m" && ./cub3d map/fail/fail-texture-format-2.cub || \
	echo "\033[0;32mnot surrounded by walls\033[0m" && ./cub3d map/fail/fail-wall-surround.cub || \
	chmod +r map/fail/fail-read-rights.cub

gdb: all
	gdb --args ./cub3d map/$(TESTMAP)


.PHONY: clean fclean re libft mlx

-include $(OBJ:.o=.d)
