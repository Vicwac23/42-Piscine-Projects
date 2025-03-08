#include "libvic.h"

int	main(int argc, char **argv)
{
	t_buffer	temp;
	t_buffer	buffer;
	int			fd;
	int			i;

	if (argc >= 2)
	{
		buffer.filled = 0;
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (!fd)
				ft_putstr(strerror(errno));
			temp = file_to_malloc(fd);
			if (argc > 2)
				add_file_to_buffer(temp, &buffer);
			else
				buffer = temp;
			close(fd);
		}
		file_to_hex_to_write(buffer.buff);
	}
	return (0);
}
