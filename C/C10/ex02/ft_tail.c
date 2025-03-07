#include "libvic.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	check_c_option_bytes(char *value)
{
	int	sol;
	int	len;
	int	i;

	len = 0;
	while (value[len])
	{
		if (!(value[len] >= '0' && value[len] <= '9'))
		{
			ft_putstr("Invalid number of bytes\n");
			return (-1);
		}
		len++;
	}
	i = 0;
	sol = 0;
	while (i < len)
	{
		sol += sol * 10 + (value[i] - '0');
		i++;
	}
	return (sol);
}

void	read_bytes_from_file(int fd, int n)
{
	t_buffer	buffer;

	buffer = file_malloc(fd);
	if (buffer.filled > 0)
	{
		if (n >= 0)
			buffer.arr += buffer.filled - n;
		ft_putstr(buffer.arr);
	}
}

void	open_read_close_file(int *fd, int byte_num, char *file)
{
	*fd = open(file, O_RDONLY);
	if (!(*fd))
		ft_putstr(strerror(errno));
	read_bytes_from_file(*fd, byte_num);
	close(*fd);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	index;
	int	byte_num;

	byte_num = -1;
	if (argc >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
		{
			byte_num = check_c_option_bytes(argv[2]);
			if (byte_num == -1)
				return (-1);
		}
		index = 1;
		while (index < argc)
		{
			open_read_close_file(&fd, byte_num, argv[index]);
			index++;
		}
	}
	else
		read_bytes_from_file(0, 0);
	return (0);
}
