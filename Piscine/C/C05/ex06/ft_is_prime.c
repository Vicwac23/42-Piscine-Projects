int	ft_is_prime(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0 || nb == 1)
		return (0);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_is_prime(-3));
// 	printf("%d\n", ft_is_prime(0));
// 	printf("%d\n", ft_is_prime(7));
// 	printf("%d\n", ft_is_prime(2));
// 	printf("%d\n", ft_is_prime(41));
// }
