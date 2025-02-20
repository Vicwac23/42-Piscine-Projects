NAME	= bsq
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
SRC		= main.c check_map.c read_file.c write_map.c
OBJ		= $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Linking objects into executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJ)

# Remove object files and executable
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
