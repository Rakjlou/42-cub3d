
NAME = raycasting

VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes
#VALGRIND =
TESTMAP = test.cub
#TESTMAP = fail/fail-wall-13.cub

SRC = tmp_raycasting/raycasting3.c \

OBJ = ../$(SRC:.c=.o)
DEPS = ../$(SRC:.c=.d)

CC = gcc

LIBFT_DIR = ../libft
MLX_DIR = ../minilibx-linux

CFLAGS = -Wall -MMD -g3 \
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

-include $(OBJ:.o=.d)