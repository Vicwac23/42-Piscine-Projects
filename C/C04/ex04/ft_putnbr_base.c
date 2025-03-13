#include <unistd.h>

void	ft_putnbr_recursive(int nbr, char *base, int len)
{
	int	temp;

	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		temp = 8;
		ft_putnbr_recursive(-(nbr / len), base, len);
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			write(1, "-", 1);
		}
		temp = nbr % len;
		if (nbr >= len)
			ft_putnbr_recursive(nbr / len, base, len);
	}
	write(1, &base[temp], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-')
			return ;
		i = len + 1;
		while (base[i] != '\0')
		{
			if (base[len] == base[i])
				return ;
			i++;
		}
		len++;
	}
	if (len <= 1)
		return ;
	ft_putnbr_recursive(nbr, base, len);
}
