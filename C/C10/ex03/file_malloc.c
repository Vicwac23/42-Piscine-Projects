#include "libvic.h"

int	read_expand(int fd, char **buffer, int *filled, int *capacity)
{
	char	*new_buffer;
	int		bytes_read;
	int		i;

	bytes_read = read(fd, *buffer + *filled, BUFF_S);
	if (bytes_read <= 0)
		return (bytes_read);
	*filled += bytes_read;
	if (*filled >= *capacity)
	{
		*capacity *= 2;
		new_buffer = malloc(*capacity + 1);
		i = -1;
		while (++i < *filled)
			new_buffer[i] = (*buffer)[i];
		free(*buffer);
		*buffer = new_buffer;
	}
	return (bytes_read);
}

t_buffer	file_to_malloc(int fd)
{
	t_buffer	buffer;
	int			capacity;
	int			bytes_read;

	bytes_read = 0;
	buffer.filled = 0;
	capacity = BUFF_S;
	buffer.buff = malloc(capacity + 1);
	bytes_read = read_expand(fd, &buffer.buff, &buffer.filled, &capacity);
	while (bytes_read > 0)
		bytes_read = read_expand(fd, &buffer.buff, &buffer.filled, &capacity);
	buffer.buff[buffer.filled] = '\0';
	return (buffer);
}
