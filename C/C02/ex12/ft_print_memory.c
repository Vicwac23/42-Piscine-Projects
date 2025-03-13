#include <unistd.h>

void	ft_put_hex(unsigned long n, int size)
{
	char	c;

	if (size > 1)
		ft_put_hex(n / 16, size - 1);
	c = "0123456789abcdef"[n % 16];
	write(1, &c, 1);
}

void	ft_print_addr(void *addr)
{
	ft_put_hex((unsigned long)addr, 16);
	write(1, ": ", 2);
}

void	ft_print_byte_hex(unsigned char c)
{
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_print_line(unsigned char *ptr, unsigned int start, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (start + i < size)
			ft_print_byte_hex(ptr[start + i]);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < 16 && (start + i) < size)
	{
		if (ptr[start + i] >= 32 && ptr[start + i] <= 126)
			write(1, &ptr[start + i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_addr(ptr + i);
		ft_print_line(ptr, i, size);
		i += 16;
	}
	return (addr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "Bonjour les amichs.\t.c'est fou.aaaaaGGGGGGGGaaaaa";
// 	ft_print_memory(str, sizeof(str) - 1);
// 	return (0);
// }
