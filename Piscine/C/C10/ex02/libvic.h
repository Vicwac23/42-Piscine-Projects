#ifndef LIBVIC_H

# define LIBVIC_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_S 64

typedef struct s_buffer
{
	char	*arr;
	int		filled;
}	t_buffer;

t_buffer	file_malloc(int fd);

typedef struct s_argv_index
{
	char	**argv;
	int		index;
}	t_argv_index;

#endif