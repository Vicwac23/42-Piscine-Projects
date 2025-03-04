PROG_NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HEADERS = includes/ft.h

OBJECTS = $(SRCS:.c=.o)


all: $(PROG_NAME)

$(PROG_NAME): $(OBJECTS)
	ar rcs $(PROG_NAME) $(OBJECTS)

%.o: srcs/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

.PHONY: all clean fclean re