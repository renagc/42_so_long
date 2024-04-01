NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = main.c gen_hooks.c gen_window.c gen_image.c map_check_rules.c map_check_path.c draw.c map_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	make -C sources/ft_printf
	make -C sources/libft
	make -C sources/libft_ext
	$(CC) $(CFLAGS) $(SOURCES) sources/ft_printf/libftprintf.a sources/libft_ext/libft_ext.a sources/libft/libft.a mlx-linux/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

clean:
	make clean -C sources/ft_printf
	make clean -C sources/libft
	make clean -C sources/libft_ext
	$(RM) $(OBJECTS)

fclean: clean
	make fclean -C sources/ft_printf
	make fclean -C sources/libft
	make fclean -C sources/libft_ext
	$(RM) $(NAME) run

make re: fclean all
