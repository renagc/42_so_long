NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SOURCES = get_next_line.c get_next_line_utils.c
SRC_B = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)
			rm $(OBJECTS)

bonus : $(OBJS_B)
			ar rcs $(NAME) $(OBJS_B)

clean:
			$(RM) $(OBJECTS) $(OBJS_B)

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re