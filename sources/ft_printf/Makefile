NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putnbr_lu.c ft_putnbr_b.c ft_putstr.c ft_printf.c ft_putptr.c ft_putu.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	rm $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all