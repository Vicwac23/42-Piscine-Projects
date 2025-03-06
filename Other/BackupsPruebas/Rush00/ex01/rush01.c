#include <unistd.h>

void	ft_putchar(char c);

void	set_char(int x, int y, int i, int j)
{
	if ((i == 0) && (j == 0)) // Arriba Izq
		ft_putchar('/');
	else if ((i == x) && (j == 0)) // Arriba Der
		ft_putchar('\\');
	else if ((i == 0) && (j == y)) // Abajo Izq
		ft_putchar('\\');
	else if ((i == x) && (j == y)) // Abajo Der
		ft_putchar('/');

	else if ((i == 0) || (i == x)) // Lados Verticales
		ft_putchar('*');
	else if ((j == 0) || (j == y)) // Lados Horizontales
		ft_putchar('*');

	else
		ft_putchar(' '); // Relleno (vacio -> espacios)
}

void	rush(int x, int y)
{	
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;

	int i;
	int j;
	j = 0;

	while (j < y)
	{	
		i = 0;
		while (i < x)
		{
			set_char(x - 1, y - 1, i, j);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
