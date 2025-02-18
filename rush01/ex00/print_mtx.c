/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:16:14 by victmore          #+#    #+#             */
/*   Updated: 2025/02/09 17:25:11 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 6

//1.Top  2.Bottom  3.Left  4.Right
void	assign_borders(char mtx[SIZE][SIZE], char **argv)
{
	mtx[0][1] = argv[1][0];
	mtx[0][2] = argv[1][2];
	mtx[0][3] = argv[1][4];
	mtx[0][4] = argv[1][6];

	mtx[5][1] = argv[1][8];
	mtx[5][2] = argv[1][10];
	mtx[5][3] = argv[1][12];
	mtx[5][4] = argv[1][14];

	mtx[1][0] = argv[1][16];
	mtx[2][0] = argv[1][18];
	mtx[3][0] = argv[1][20];
	mtx[4][0] = argv[1][22];

	mtx[1][5] = argv[1][24];
	mtx[2][5] = argv[1][26];
	mtx[3][5] = argv[1][28];
	mtx[4][5] = argv[1][30];
}

void	print_mtx(char mtx[SIZE][SIZE])
{
	int	i;
	int	j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			write(1, " ", 1);
			if (mtx[j][i] >= '0' && mtx[j][i] <= '9')
				write(1, &mtx[j][i], 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void	fill_with_zeros(char mtx[SIZE][SIZE])
{
	int	i;
	int	j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			mtx[j][i] = 0;
			i++;
		}
		j++;
	}
}

void	set_up_mtx (char mtx[SIZE][SIZE], char **argv)
{
	fill_with_zeros(mtx);
	assign_borders(mtx, argv);
}
