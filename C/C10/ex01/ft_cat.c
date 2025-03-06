#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE 4096

void	ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_read_write_file(int fd)
{
	int	bytes_read;
	char buffer[BUFF_SIZE];

	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		ft_read_write_file(fd);
	}
	else if (bytes_read == -1)
		ft_putstr(strerror(errno));
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read_write_file(fd);
		close(fd);
	}
	else if (argc < 2)
		ft_putstr("File name missing.");
	else
		ft_putstr("Too many arguments.");
	return (0);
}