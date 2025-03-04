#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 4096

void	ft_strwrite(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	read_write_file(int	fd)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFF_SIZE)
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
		ft_strwrite("File name missing.");
	else
		ft_strwrite("Too many arguments.");
	return (0);
}