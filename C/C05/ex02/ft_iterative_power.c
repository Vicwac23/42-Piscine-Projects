int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (nb == 0 && power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_iterative_power(2, 8));
// 	printf("%d\n", ft_iterative_power(0, 8));
// 	printf("%d\n", ft_iterative_power(0, 0));
// 	printf("%d\n", ft_iterative_power(-2, 5));
// 	printf("%d\n", ft_iterative_power(2, -2));
// }