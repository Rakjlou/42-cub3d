# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/08/24 11:37:18 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# /!\ CAUTION /!\ IN PLAYER DEBUG, REMOVE DPRINTF CALLS
NAME = cub3d

VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes
#VALGRIND =
TESTMAP = test.cub
#TESTMAP = fail/fail-wall-13.cub

SRC_COMMON = src/main.c \
	src/errors/register.c \
	src/game/singleton.c \
	src/game/init.c \
	src/game/destroy.c \
	src/input/init.c \
	src/input/debug.c \
	src/input/mouse.c \
	src/render/color.c \
	src/render/circle.c \
	src/render/render_colliders.c \
	src/render/texture.c \
	src/render/window/destroy.c \
	src/render/window/refresh.c \
	src/render/window/pixel.c \
	src/render/window/set_callback.c \
	src/render/window/set_key_callback.c \
	src/render/rect/get.c \
	src/render/rect/init.c \
	src/render/rect/render.c \
	src/player/init.c \
	src/player/debug.c \
	src/player/move_horizontal.c \
	src/player/move_vertical.c \
	src/player/rotate.c \
	src/player/update_movement.c \
	src/map/init.c \
	src/map/parse.c \
	src/map/destroy.c \
	src/map/build_matrix.c \
	src/map/debug.c \
	src/map/candidate_debug.c \
	src/map/iterate.c \
	src/map/tile_is.c \
	src/map/tile_collides.c \
	src/map/get_tile.c \
	src/map/validation/is_valid.c \
	src/map/validation/check_emptiness.c \
	src/map/validation/check_filename.c \
	src/map/validation/check_spawn.c \
	src/map/validation/check_metadata.c \
	src/map/validation/check_metadata_errors.c \
	src/map/validation/check_metadata_helpers.c \
	src/map/validation/check_walls.c \
	src/map/minimap/render.c \
	src/map/minimap/render_colliders.c \
	src/vectors/add.c \
	src/vectors/mult.c \
	src/raycasting/compute.c \
	src/raycasting/ray_init.c \
	src/raycasting/ray_hit.c \

SRC_MANDATORY = src/game/loop.c \
	src/player/update.c \
	src/map/validation/check_map_chars.c \
	src/raycasting/raycast_wall_from_wcolumn.c \
	src/render/window/init.c \
	src/map/validation/tile_is.c \

SRC_BONUS = $(SRC_MANDATORY:.c=_bonus.c)

OBJ_COMMON = $(SRC_COMMON:.c=.o)
DEPS_COMMON = $(SRC_COMMON:.c=.d)

OBJ_MANDATORY = $(OBJ_COMMON) $(SRC_MANDATORY:.c=.o)
DEPS_MANDATORY = $(DEPS_COMMON) $(SRC_MANDATORY:.c=.d)

OBJ_BONUS = $(OBJ_COMMON) $(SRC_BONUS:.c=.o)
DEPS_BONUS = $(DEPS_COMMON) $(SRC_BONUS:.c=.d)

OBJ_ALL = $(OBJ_COMMON) $(SRC_MANDATORY:.c=.o) $(SRC_BONUS:.c=.o)
DEPS_ALL = $(DEPS_COMMON) $(SRC_MANDATORY:.c=.d) $(SRC_BONUS:.c=.d)

CC = cc

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

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJ_MANDATORY)
	$(CC) $(OBJ_MANDATORY) -o $@ $(LDFLAGS) $(LDLIBS)

$(NAME)_bonus: $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME)_bonus $(LDFLAGS) $(LDLIBS)

bonus: libft mlx $(NAME)_bonus

libft:
	make --no-print-directory -C $(LIBFT_DIR)

mlx:
	make --no-print-directory -C $(MLX_DIR)

clean:
	make --no-print-directory -C $(LIBFT_DIR) clean
	make --no-print-directory -C $(MLX_DIR) clean
	rm -f $(OBJ_ALL) $(DEPS_ALL)

fclean: clean
	make --no-print-directory -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean
	make all

rt: fclean test

n:
	norminette inc src libft

t:
	$(VALGRIND)	./cub3d map/$(m).ber

test: all
	$(VALGRIND)	./cub3d map/$(TESTMAP)

test_failure: all
	chmod -r map/fail/fail-read-rights.cub && \
	echo "\033[0;32m.cub file\033[0m"                   && $(VALGRIND) ./cub3d map/fail/.cub ; \
	echo "\033[0;32mnon existing file\033[0m"           && $(VALGRIND) ./cub3d map/fail/idontexist.cub ; \
	echo "\033[0;32mduplicate spawn\033[0m"             && $(VALGRIND) ./cub3d map/fail/fail-duplicate-spawn.cub ; \
	echo "\033[0;32mempty map\033[0m"                   && $(VALGRIND) ./cub3d map/fail/fail-empty.cub ; \
	echo "\033[0;32mwrong extension\033[0m"             && $(VALGRIND) ./cub3d map/fail/fail-extension.cu ; \
	echo "\033[0;32mno spawn\033[0m"                    && $(VALGRIND) ./cub3d map/fail/fail-lacks-spawn.cub ; \
	echo "\033[0;32mno read rights\033[0m"              && $(VALGRIND) ./cub3d map/fail/fail-read-rights.cub ; \
	echo "\033[0;32munknown char\033[0m"                && $(VALGRIND) ./cub3d map/fail/fail-unknown-char.cub ; \
	echo "\033[0;32mcolor negative\033[0m"              && $(VALGRIND) ./cub3d map/fail/fail-color-negative.cub ; \
	echo "\033[0;32mcolor too high\033[0m"              && $(VALGRIND) ./cub3d map/fail/fail-color-too-high.cub ; \
	echo "\033[0;32mcolor missing\033[0m"               && $(VALGRIND) ./cub3d map/fail/fail-color-missing.cub ; \
	echo "\033[0;32mcolor format (1 block)\033[0m"      && $(VALGRIND) ./cub3d map/fail/fail-color-format.cub ; \
	echo "\033[0;32mcolor format (> 2 blocks)\033[0m"   && $(VALGRIND) ./cub3d map/fail/fail-color-format-2.cub ; \
	echo "\033[0;32mtexture missing\033[0m"             && $(VALGRIND) ./cub3d map/fail/fail-texture-missing.cub ; \
	echo "\033[0;32mtexture format (1 block)\033[0m"    && $(VALGRIND) ./cub3d map/fail/fail-texture-format.cub ; \
	echo "\033[0;32mtexture format (> 2 blocks)\033[0m" && $(VALGRIND) ./cub3d map/fail/fail-texture-format-2.cub ; \
	echo "\033[0;32mtexture file\033[0m"                && $(VALGRIND) ./cub3d map/fail/fail-texture-file.cub ; \
	echo "\033[0;32mtexture file 2\033[0m"              && $(VALGRIND) ./cub3d map/fail/fail-texture-file2.cub ; \
	echo "\033[0;32mwalls (south limit)\033[0m"         && $(VALGRIND) ./cub3d map/fail/fail-wall.cub ; \
	echo "\033[0;32mwalls (spawn south limit)\033[0m"   && $(VALGRIND) ./cub3d map/fail/fail-wall-2.cub ; \
	echo "\033[0;32mwalls (enclosed)\033[0m"            && $(VALGRIND) ./cub3d map/fail/fail-wall-3.cub ; \
	echo "\033[0;32mwalls (spawn only)\033[0m"          && $(VALGRIND) ./cub3d map/fail/fail-wall-4.cub ; \
	echo "\033[0;32mwalls (outside south)\033[0m"       && $(VALGRIND) ./cub3d map/fail/fail-wall-5.cub ; \
	echo "\033[0;32mwalls (outside east)\033[0m"        && $(VALGRIND) ./cub3d map/fail/fail-wall-6.cub ; \
	echo "\033[0;32mwalls (outside north)\033[0m"       && $(VALGRIND) ./cub3d map/fail/fail-wall-7.cub ; \
	echo "\033[0;32mwalls (outside west)\033[0m"        && $(VALGRIND) ./cub3d map/fail/fail-wall-8.cub ; \
	echo "\033[0;32mwalls (east limit)\033[0m"          && $(VALGRIND) ./cub3d map/fail/fail-wall-9.cub ; \
	echo "\033[0;32mwalls (north limit)\033[0m"         && $(VALGRIND) ./cub3d map/fail/fail-wall-10.cub ; \
	echo "\033[0;32mwalls (west limit)\033[0m"          && $(VALGRIND) ./cub3d map/fail/fail-wall-11.cub ; \
	echo "\033[0;32mwalls (space inside)\033[0m"        && $(VALGRIND) ./cub3d map/fail/fail-wall-12.cub ; \
	echo "\033[0;32mwalls (spawn & space only)\033[0m"  && $(VALGRIND) ./cub3d map/fail/fail-wall-12.cub ; \
	chmod +r map/fail/fail-read-rights.cub

gdb: all
	gdb --args ./cub3d map/$(TESTMAP)


.PHONY: clean fclean re libft mlx

-include $(OBJ_ALL:.o=.d)
