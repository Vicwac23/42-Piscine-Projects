#include <unistd.h>
#include <stdbool.h>

#define SIZE 6

void	set_up_mtx(char mtx[SIZE][SIZE], char **argv);

void	print_mtx(char mtx[SIZE][SIZE]);

int	visible_blocks_tl(int *arr)
{
	int	i;
	int	max_height;
	int	cont;

	i = 0;
	max_height = 0;
	cont = 0;
	while (i < SIZE - 2)
	{
		if (arr[i] > max_height)
		{
			max_height = arr[i];
			cont++;
		}
		i++;
	}
	return (cont);
}

int	visible_blocks_br(int *arr)
{
	int	i;
	int	max_height;
	int	cont;

	i = SIZE - 2;
	max_height = 0;
	cont = 0;
	while (i >= 0)
	{
		if (arr[i] > max_height)
		{
			max_height = arr[i];
			cont++;
		}
		i--;
	}
	return (cont);
}

bool	top_valid (char mtx[SIZE][SIZE], int col)
{
	int	buildings[SIZE - 2];
	int	i;

	i = 0;
	while (i < SIZE - 2)
	{
		buildings[i] = mtx[i + 1][col] - '0';
		i++;
	}
	return (visible_blocks_tl(buildings) == (mtx[0][col] - '0'));
}

bool	bottom_valid (char mtx[SIZE][SIZE], int col)
{
	int	buildings[SIZE - 2];
	int	i;

	i = SIZE - 3;
	while (i >= 0)
	{
    		buildings[SIZE - 3 - i] = mtx[i + 1][col] - '0';
    		i--;
	}
	return (visible_blocks_br(buildings) == (mtx[SIZE - 1][col] - '0'));
}

bool	left_valid (char mtx[SIZE][SIZE], int row)
{
	int	buildings[SIZE - 2];
	int	i;

	i = 0;
	while (i < SIZE - 2)
	{
		buildings[i] = mtx[row][i + 1] - '0';
		i++;
	}
	return (visible_blocks_tl(buildings) == (mtx[row][0] - '0'));
}

bool	right_valid (char mtx[SIZE][SIZE], int row)
{
	int	buildings[SIZE - 2];
	int	i;

	i = 0;
	while (i < SIZE - 2)
	{
		buildings[i] = mtx[row][i + 1] - '0';
		i++;
	}
	return (visible_blocks_br(buildings) == (mtx[row][SIZE - 1] - '0'));
}

bool	is_safe(char mtx[SIZE][SIZE], int col, int row, int num) //num is current number 1-4
{
	int	i;

	i = 0;
	while (i < SIZE - 2)
		if (mtx[col][i] == num)
			return false;

	i = 0;
	while (i < SIZE - 2)
		if (mtx[i][row] == num)
			return false;
	
	mtx[row][col] = num + '0';

	if ((mtx[0][col] != '0' && !top_valid(mtx, col)) ||
	    (mtx[SIZE - 1][col] != '0' && !bottom_valid(mtx, col)) ||
	    (mtx[row][0] != '0' && !left_valid(mtx, row)) ||
	    (mtx[row][SIZE - 1] != '0' && !right_valid(mtx, row))) 
	{
		mtx[row][col] = '0';
		return false;
	}
	mtx[row][col] = '0';
	return true;
}

bool	solve_recursive(char mtx[SIZE][SIZE], int row, int col)
{
	int	num;

	num = 1;
	if (row == SIZE - 2 && col == SIZE - 1)
		return true;
	if (col == SIZE - 1)
	{
		row++;
		col = 0;
	}
	if (mtx[row][col] != 0)
		return solve_recursive(mtx, row, col + 1);
	while (num <= SIZE - 2)
	{
		if (is_safe(mtx, row, col, num))
		{
			mtx[row][col] = num;
			if (solve_recursive(mtx, row, col + 1))
				return (true);
			mtx[row][col] = 0;
		}
		num++;
	}
	return (false);
}

void	solve(char mtx[SIZE][SIZE])
{
	solve_recursive(mtx, 0, 0);
}

int	main(int argc, char **argv)
{
	char	mtx[SIZE][SIZE];

	if (argc != 2)
		return (1);

	set_up_mtx(mtx, argv);
	solve(mtx);
	print_mtx(mtx);

	return (0);
}
