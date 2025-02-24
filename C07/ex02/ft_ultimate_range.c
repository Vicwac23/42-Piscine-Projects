#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (size));
	if (!*range)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i = -1;
// 	int	a = -2;
// 	int	b = 9;
// 	int *x;
// 	int	size = ft_ultimate_range(&x, a, b);
// 	printf("%d\n", size);
// 	while (++i < (b - a))
// 		printf("%d, ", x[i]);
// 	return (0);
// }