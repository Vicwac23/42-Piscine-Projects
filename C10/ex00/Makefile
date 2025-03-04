PROG_NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_write_file.c
OBJECTS = $(SOURCES:.c=.o)

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

.PHONY: all clean fclean