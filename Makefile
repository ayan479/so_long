NAME = so_long

CC = clang
CFLAGS = -Wall -Werror -Wextra -gdwarf-4

SOURCE := *.c
UTILS := utils/*.c
LIBRARY := -lm -lbsd -L./mlx -lmlx -lXext -lX11

MLX = mlx

all: $(NAME)

$(NAME):
	make -C $(MLX)
	$(CC) $(CFLAGS) $(SOURCE) $(UTILS) $(LIBRARY) -o $(NAME)

clean:
	rm -f $(SOURCE:.c=.o)
	$(MAKE) clean -C $(MLX)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re