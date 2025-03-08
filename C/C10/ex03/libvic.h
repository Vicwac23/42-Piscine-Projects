#ifndef LIBVIC_H

# define LIBVIC_H
# define BUFF_S 64

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_buffer
{
	char	*buff;
	int		filled;
}	t_buffer;

typedef struct s_quadcount
{
	int	x;
	int	y;
	int	z;
	int	a;
}	t_quadcount;

void		ft_putstr(char *str);

void		add_file_to_buffer(t_buffer temp, t_buffer *buffer);

void		initialize_quadcount(t_quadcount *quadcount, int x, int y, int z);

char		ascii_to_hex(int n);

t_buffer	file_to_malloc(int fd);

void		file_to_hex_to_write(char *buffer);

#endif