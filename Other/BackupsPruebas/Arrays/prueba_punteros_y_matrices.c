#include <unistd.h>

void	print_matrix(char matrix[3][3], int x_len, int y_len)
{
	int i;
	int j;

	i = 0;

	while (i < x_len)
	{	
		j = 0;
		while (j < y_len)
		{
			write(1, &matrix[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{

	char mtx[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	print_matrix(mtx, 3, 3);

	return (0);
}

