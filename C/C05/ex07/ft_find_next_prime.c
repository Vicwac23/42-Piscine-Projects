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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_find_next_prime(-3));
// 	printf("%d\n", ft_find_next_prime(0));
// 	printf("%d\n", ft_find_next_prime(7));
// 	printf("%d\n", ft_find_next_prime(4));
// 	printf("%d\n", ft_find_next_prime(42));
// }
