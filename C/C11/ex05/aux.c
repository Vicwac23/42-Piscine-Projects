#include <unistd.h>

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

void	ft_putnbr(int nb)
{
	int	temp;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		temp = 8 + '0';
		ft_putnbr(-(nb / 10));
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		temp = nb % 10 + '0';
		if (nb > 9)
			ft_putnbr(nb / 10);
	}
	write(1, &temp, 1);
}
