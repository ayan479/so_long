NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iheaders -g3

SOURCE := *.c
UTILS := utils/*c
LIBRARY := -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX := mlx/

all:
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SOURCE) $(UTILS) $(LIBRARY) -o $(NAME)

clean:
	rm -f $(SOURCE:.c=.o)
	$(MAKE) clean -C mlx

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re