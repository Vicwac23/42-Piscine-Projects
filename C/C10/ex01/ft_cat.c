#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE 29000

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

void	ft_read_write_to_std(void)
{
	char	buffer[BUFF_SIZE];
	int		bytes_read;
	
	while(1)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFF_SIZE);
		if (bytes_read <= 0)
			break;
		write(STDOUT_FILENO, buffer, bytes_read);
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int	index;

	if (argc >= 2)
	{
		index = 1;
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			if (!fd)
				ft_putstr(strerror(errno));
			ft_read_write_file(fd);
			close(fd);
			index++;
		}
	}
	else
		ft_read_write_to_std();
	return (0);
}