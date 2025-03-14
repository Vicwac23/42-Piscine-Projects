#include "libvic.h"

void	swap_adjacent(char **buffer)
{
	int		i;
	char	temp;

	i = 0;
	while ((*buffer)[i] != '\0' && (*buffer)[i + 1] != '\0')
	{
		temp = (*buffer)[i];
		(*buffer)[i] = (*buffer)[i + 1];
		(*buffer)[i + 1] = temp;
		i += 2;
	}
}

void	write_char_in_hex(char c, int x, int *a)
{
	char	two_hex[3];

	two_hex[0] = ascii_to_hex(c / 16);
	two_hex[1] = ascii_to_hex(c % 16);
	two_hex[2] = '\0';
	ft_putstr(two_hex);
	if (x % 2 == 1 && x < 15)
	{
		write(1, " ", 1);
		(*a)++;
	}
}

void	print_last_return(int a)
{
	if (a == 9)
		write(1, "    ", 4);
	else
		write(1, "     ", 5);
}

void	print_offset(int count, int c_count, int is_end, int a)
{
	char	offset[8];
	int		num;
	int		i;

	if (is_end == 1)
	{
		while (++a < 10)
			print_last_return(a);
		write(1, "\n", 1);
	}
	num = c_count * 16 + count;
	i = 6;
	offset[7] = '\0';
	while (i >= 0)
	{
		offset[i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i--;
	}
	ft_putstr(offset);
	if (is_end == 1)
		write(1, "\n", 1);
	else
		write(1, " ", 1);
}

void	file_to_hex_to_write(char *buffer)
{
	int			i;
	t_quadcount	quadcount;

	i = -1;
	initialize_quadcount(&quadcount, 0, 0, 0);
	swap_adjacent(&buffer);
	while (buffer[++i])
	{
		if (quadcount.x == 0)
			print_offset(quadcount.x, quadcount.y, quadcount.z, quadcount.a);
		write_char_in_hex(buffer[i], quadcount.x, &quadcount.a);
		if (quadcount.x == 15)
		{
			quadcount.x = 0;
			quadcount.y++;
			quadcount.a = 1;
			write(1, "\n", 1);
		}
		else
			quadcount.x++;
	}
	quadcount.z = 1;
	if (quadcount.x != 0)
		print_offset(quadcount.x, quadcount.y, quadcount.z, quadcount.a);
}
