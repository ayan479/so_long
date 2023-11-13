NAME = so_long

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_PATH	=	./mlxl/
	MLX			=	libmlxl.a
	MLXFLAGS	=	-lm -lbsd -lmlx -lXext -lX11
	CC			=	clang
	CFLAGS		=	-Wall -Werror -Wextra -gdwarf-4
else
	MLX_PATH	=	./mlx/
	MLX			=	libmlx.a
	MLXFLAGS	=	-L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit
	CC			=	cc
	CFLAGS		=	-Wall -Werror -Wextra ${HEADER}
endif

SOURCE := *.c
UTILS := utils/*c

all: $(NAME)

$(NAME): $(SOURCE) $(UTILS)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(SOURCE) $(UTILS) $(MLX_PATH)$(MLX) -o $(NAME) $(MLXFLAGS)

clean:
	rm -f $(SOURCE:.c=.o)
	$(MAKE) clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re