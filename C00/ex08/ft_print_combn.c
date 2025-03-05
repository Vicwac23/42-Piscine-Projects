#include <unistd.h>

void	print_comb(int n, int *comb)
{
	int		i;
	char	temp;

	i = 0;
	while (i < n)
	{
		temp = comb[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	if (comb[0] < 10 - n)
		write(1, ", ", 2);
	else
		write(1, "\n", 1);
}

void	generate_comb(int n, int *comb, int index, int start)
{
	int	i;

	if (index == n)
	{
		print_comb(n, comb);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		comb[index] = i;
		generate_comb(n, comb, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];

	generate_comb(n, comb, 0, 0);
}

// int	main(void)
// {
// 	ft_print_combn(1);
// }
