NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders -g3

SOURCE := *.c
GETNEXTLINE := utils/*c
LIBRARY := -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX := mlx/

all:
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	rm -f $(SOURCE:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re