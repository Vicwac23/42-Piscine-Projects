PROG_NAME = do_op
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_list_push_strs.c ../aux.c
OBJS = $(SRCS:.c=.o)
HDRS = ft_list.h

all: $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG_NAME)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

.PHONY: all clean fclean re