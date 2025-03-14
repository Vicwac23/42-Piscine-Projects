#include "libvic.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

void	add_file_to_buffer(t_buffer temp, t_buffer *buffer)
{
	t_buffer	new_buffer;
	int			origin_size;
	int			i;
	int			j;

	origin_size = (*buffer).filled;
	(*buffer).filled += temp.filled;
	new_buffer.buff = malloc((*buffer).filled + 1);
	i = 0;
	while (i < origin_size)
	{
		new_buffer.buff[i] = ((*buffer).buff)[i];
		i++;
	}
	j = 0;
	while (i < (*buffer).filled)
	{
		new_buffer.buff[i] = temp.buff[j];
		i++;
		j++;
	}
	new_buffer.buff[(*buffer).filled] = '\0';
	if ((*buffer).filled > 0)
		free((*buffer).buff);
	(*buffer).buff = new_buffer.buff;
}

void	initialize_quadcount(t_quadcount *quadcount, int x, int y, int z)
{
	(*quadcount).x = x;
	(*quadcount).y = y;
	(*quadcount).z = z;
	(*quadcount).a = 1;
}

char	ascii_to_hex(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n >= 10 && n <= 15)
		return (n - 10 + 'a');
	return ('?');
}
