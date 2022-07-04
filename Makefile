# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/07/01 21:21:02 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

TESTMAP = estupid.ber

SRC = src/main.c \
	src/errors/register.c \
	src/map/init.c \
	src/map/parse.c \
	src/map/destroy.c \
	src/map/validation/is_valid.c \
	src/map/validation/check_emptiness.c \
	src/map/validation/check_filename.c \
	src/map/validation/check_map_chars.c \

OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

CC = gcc

LIBFT_DIR = libft
MLX_DIR = minilibx-linux

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -MMD -g3 \
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
	./so_long map/$(m).ber

test: all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes \
	./so_long map/$(TESTMAP)

test_failure: all
	chmod -r map/fail/fail-read-rights.ber && \
	echo "\033[0;32m.ber file\033[0m" && ./so_long map/fail/.ber || \
	echo "\033[0;32mduplicate exit\033[0m" && ./so_long map/fail/fail-duplicate-exit.ber || \
	echo "\033[0;32mnon existing file\033[0m" && ./so_long map/fail/idontexist.ber || \
	echo "\033[0;32mduplicate spawn\033[0m" && ./so_long map/fail/fail-duplicate-spawn.ber || \
	echo "\033[0;32mempty map\033[0m" && ./so_long map/fail/fail-empty.ber || \
	echo "\033[0;32mwrong extension\033[0m" && ./so_long map/fail/fail-extension.be || \
	echo "\033[0;32mno special case\033[0m" && ./so_long map/fail/fail-lacks-all.ber || \
	echo "\033[0;32mno collectible\033[0m" && ./so_long map/fail/fail-lacks-collectible.ber || \
	echo "\033[0;32mno exit\033[0m" && ./so_long map/fail/fail-lacks-exit.ber || \
	echo "\033[0;32mno spawn\033[0m" && ./so_long map/fail/fail-lacks-spawn.ber || \
	echo "\033[0;32mno read rights\033[0m" && ./so_long map/fail/fail-read-rights.ber || \
	echo "\033[0;32munknown char\033[0m" && ./so_long map/fail/fail-unknown-char.ber || \
	echo "\033[0;32mnot surrounded by walls\033[0m" && ./so_long map/fail/fail-wall-rectangle.ber || \
	echo "\033[0;32mnot rectangle\033[0m" && ./so_long map/fail/fail-not-rectangle.ber || \
	chmod +r map/fail/fail-read-rights.ber

gdb: all
	gdb --args ./so_long map/$(TESTMAP)


.PHONY: clean fclean re libft mlx

-include $(OBJ:.o=.d)
