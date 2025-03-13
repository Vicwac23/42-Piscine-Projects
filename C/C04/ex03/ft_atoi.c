int	ft_atoi(char *str)
{
	int	sol;
	int	sign;
	int	i;

	i = 0;
	sol = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sol = sol * 10 + (str[i] - '0');
		i++;
	}
	return (sol * sign);
}
