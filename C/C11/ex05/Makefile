PROG_NAME = do_op
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c \
		ops.c \
		aux.c
OBJS = $(SRCS:.c=.o)
HDRS = libvic.h

all: $(PROG_NAME)

$(PROG_NAME): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

.PHONY: all clean fclean re