#include <unistd.h>

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

// void	ft_putnbr(int nb)
// {
// 	int	temp;

// 	temp = nb % 10 + '0';
// 	if (nb > 9)
// 		ft_putnbr(nb / 10);
// 	write(1, &temp, 1);
// }
