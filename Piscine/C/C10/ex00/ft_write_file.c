#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 30

void	read_write_file(int fd)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		read_write_file(fd);
	}
	if (bytes_read == -1)
		write(1, "Cannot read file.", 17);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_write_file(fd);
		close(fd);
	}
	else if (argc < 2)
		write(1, "File name missing.", 18);
	else
		write(1, "Too many arguments.", 19);
	return (0);
}
