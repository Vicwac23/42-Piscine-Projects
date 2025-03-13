#include <unistd.h>
#define SIZE 10

void	ft_print_array(int *arr)
{
	int		i;
	char	temp;

	i = -1;
	while (++i < SIZE)
	{
		temp = arr[i] + '0';
		write(1, &temp, 1);
	}
	write(1, "\n", 1);
}

int	ft_is_safe(int *arr, int col, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		if (arr[i] == col)
			return (0);
	i = -1;
	while (++i < row)
		if (arr[i] == col - (row - i) || arr[i] == col + (row - i))
			return (0);
	return (1);
}

void	ft_solve(int arr[], int col, int row, int *sol_num)
{
	if (row >= SIZE)
	{
		(*sol_num)++;
		ft_print_array(arr);
		return ;
	}
	if (col >= SIZE)
		return ;
	if (ft_is_safe(arr, col, row))
	{
		arr[row] = col;
		ft_solve(arr, 0, row + 1, sol_num);
	}
	ft_solve(arr, col + 1, row, sol_num);
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[SIZE];
	int	sol_num;
	int	i;

	i = -1;
	while (++i < SIZE)
		arr[i] = -1;
	ft_solve(arr, 0, 0, &sol_num);
	return (sol_num);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_ten_queens_puzzle());
// }
