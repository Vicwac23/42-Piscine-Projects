#include <stdlib.h>

int	get_index(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

int	atoi_recursive(char *nbr, char *base_from, int digit, int base_len)
{
	int	index;

	index = get_index(nbr[digit - 1], base_from);
	if (index == -1 || !nbr[digit - 1])
		return (0);
	return (index + base_len
		* atoi_recursive(nbr, base_from, digit - 1, base_len));
}

char	*ft_itoa_malloc(long *nb, int nbr_len, int *limit)
{
	char	*result;

	if (*nb < 0)
	{
		result = malloc(sizeof(char) * (nbr_len + 2));
		*nb = -*nb;
		result[0] = '-';
		*limit = 0;
		result[nbr_len + 1] = '\0';
	}
	else
	{
		result = malloc(sizeof(char) * (nbr_len + 1));
		result[nbr_len] = '\0';
		*limit = -1;
	}
	return (result);
}

int	is_valid_nbr(char *nbr, char *base_from)
{
	int	i;
	int	j;
	int	val;

	j = 0;
	while (nbr[j])
	{
		i = 0;
		val = 0;
		while (base_from[i])
		{
			if (nbr[j] == base_from[i])
				val = 1;
			i++;
		}
		if (val == 0)
			return (0);
		j++;
	}
	return (1);
}
