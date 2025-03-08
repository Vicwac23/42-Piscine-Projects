PROG_NAME = ft_hexdump
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = 	ft_hexdump.c \
			aux.c \
			file_malloc.c \
			hex_and_read.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = libvic.h

all: $(PROG_NAME)

$(PROG_NAME): $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROG_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

.PHONY: all clean fclean re