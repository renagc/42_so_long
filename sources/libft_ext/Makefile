NAME = libft_ext.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SOURCES =	ft_iscinstr.c ft_strsdup.c ft_free_array.c ft_cp_array.c

OBJECTS = $(SOURCES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)
			rm $(OBJECTS)

clean:
			$(RM) $(OBJECTS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re