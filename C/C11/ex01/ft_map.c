#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*sol;
	int	i;

	sol = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		sol[i] = (*f)(tab[i]);
		i++;
	}
	return (sol);
}
