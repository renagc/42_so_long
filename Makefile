NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = main.c gen_hooks.c gen_window.c gen_image.c map.c map_check_path.c draw.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	make -C sources/ft_printf
	make -C sources/get_next_line
	make -C sources/libft
	make -C sources/libft_ext
	$(CC) $(CFLAGS) $(SOURCES) sources/get_next_line/get_next_line.a sources/libft_ext/libft_ext.a sources/libft/libft.a -lbsd -lmlx -lXext -lX11 -o run
	rm $(OBJECTS)

clean:
	make clean -C sources/ft_printf
	make clean -C sources/get_next_line
	make clean -C sources/libft
	make clean -C sources/libft_ext
	$(RM) $(OBJECTS)

fclean: clean
	make fclean -C sources/ft_printf
	make fclean -C sources/get_next_line
	make fclean -C sources/libft
	make fclean -C sources/libft_ext
	$(RM) $(NAME) run

make re: fclean all
