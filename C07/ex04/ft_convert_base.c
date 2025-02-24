#include <stdlib.h>

int		atoi_recursive(char *nbr, char *base_from, int digit, int base_len);

char	*ft_itoa_malloc(long *nb, int nbr_len, int *limit);

int		is_valid_nbr(char *nbr, char *base_from);

int	ft_nbr_len(long nb, int base_len)
{
	int	nbr_len;

	nbr_len = 0;
	if (nb == 0)
		nbr_len = 1;
	while (nb != 0)
	{
		nb /= base_len;
		nbr_len++;
	}
	return (nbr_len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	atoi_base(char *nbr, char *base_from)
{
	int	base_len;
	int	digit;

	digit = 0;
	while (nbr[digit])
		digit++;
	base_len = 0;
	while (base_from[base_len])
		base_len++;
	return (atoi_recursive(nbr, base_from, digit, base_len));
}

char	*itoa_base(int nbr, char *base_to)
{
	char	*result;
	int		base_len;
	int		nbr_len;
	long	nb;
	int		limit;

	nb = nbr;
	base_len = 0;
	while (base_to[base_len])
		base_len++;
	nbr_len = ft_nbr_len(nb, base_len);
	nb = nbr;
	result = ft_itoa_malloc(&nb, nbr_len, &limit);
	if (limit == -1)
		nbr_len--;
	while (nbr_len > limit)
	{
		result[nbr_len] = base_to[nb % base_len];
		nb /= base_len;
		nbr_len--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	char	*result;
	int		sign;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\n'
		|| *nbr == '\v' || *nbr == '\f' || *nbr == '\r')
		nbr++;
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	if (!is_valid_nbr(nbr, base_from))
		return (NULL);
	decimal = sign * atoi_base(nbr, base_from);
	result = itoa_base(decimal, base_to);
	return (result);
}

#include <stdio.h>
int	main(void)
{
	char base1[] = "0123456789abcdef";
	char base2[] = "01";
	char *result = ft_convert_base(" -10000000000", base1, base2);
	char *result2 = ft_convert_base("	 2", base1, base2);
	printf("= %s\n", result);
	if(result)
		free(result);
	printf("= %s\n", result2);
	if(result2)
		free(result2);
	return (0);
}
