PROG_NAME = ft_cat
SOURCES = ft_cat.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(PROG_NAME)

$(PROG_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROG_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

.PHONY: all clean fclean re