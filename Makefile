CC	= gcc

RM	= rm -f

NAME = my_hunter

SRC	=   display_image.c   \
        create_my_window.c  \
        my_putstr.c \
        my_putchar.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -l csfml-graphics -l csfml-window -l csfml-system

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
