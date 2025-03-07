#include "libvic.h"

int	read_and_expand(int fd, char **buffer, int *filled, int *capacity)
{
	int		bytes_read;
	char	*new_buffer;
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

t_buffer	file_malloc(int fd)
{
	t_buffer	buff;
	int			bytes_read;
	int			capacity;

	buff.filled = 0;
	capacity = BUFF_S;
	buff.arr = malloc(capacity + 1);
	bytes_read = read_and_expand(fd, &buff.arr, &buff.filled, &capacity);
	while (bytes_read > 0)
		bytes_read = read_and_expand(fd, &buff.arr, &buff.filled, &capacity);
	if (buff.filled == 0)
	{
		free(buff.arr);
		return (buff);
	}
	buff.arr[buff.filled] = '\0';
	return (buff);
}

// int main(int argc, char **argv)
// {
// 	int fd;
// 	char *buffer;

// 	if (argc >= 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		if (fd < 0)
// 		{
// 			perror("open");
// 			return 1;
// 		}

// 		buffer = file_malloc(fd);
// 		close(fd);

// 		if (buffer)
// 		{
// 			printf("%s", buffer);
// 			free(buffer);
// 		}
// 		else
// 		{
// 			printf("Error: Could not read file.\n");
// 		}
// 	}
// 	else
// 	{
// 		printf("Usage: %s <filename>\n", argv[0]);
// 	}
// 	return 0;
// }
