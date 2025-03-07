PROG_NAME = ft_tail
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES =	file_malloc.c	\
			ft_tail.c
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