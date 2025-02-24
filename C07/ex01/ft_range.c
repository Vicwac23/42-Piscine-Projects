#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = 0;
	while ((min + i) < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i = -1;
// 	int	a = -2;
// 	int	b = 9999;
// 	int	*x = ft_range(a, b);
// 	while (++i < (b - a))
// 		printf("%d, ", x[i]);
// 	return (0);
// }