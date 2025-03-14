#include <unistd.h>

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_recursive(char *str, char *base, int base_len, int digit)
{
	int	index;

	if (digit < 0)
		return (0);
	index = get_index(str[digit], base);
	if (index == -1)
		return (0);
	return (index + base_len
		* ft_atoi_recursive(str, base, base_len, digit - 1));
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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	str_len;
	int	sign;

	base_len = 0;
	if (!is_valid_base(base))
		return (0);
	while (base[base_len] != '\0')
		base_len++;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	str_len = 0;
	while (str[str_len] && get_index(str[str_len], base) != -1)
		str_len++;
	if (str_len == 0)
		return (0);
	return (sign * ft_atoi_recursive(str, base, base_len, str_len - 1));
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	int	temp;

// 	if (argc == 3)
// 	{
// 		temp = ft_atoi_base(argv[1], argv[2]);
// 		printf("%d", temp);
// 	}
// 	return (0);
// }
