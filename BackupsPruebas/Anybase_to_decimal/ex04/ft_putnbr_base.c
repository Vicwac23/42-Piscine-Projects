/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:27:43 by victmore          #+#    #+#             */
/*   Updated: 2025/02/13 16:08:24 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ft_pow(int num, int power)
{
    int result;

    result = 1;
    while (power > 0)
    {
        result *= num;
        power--;
    }
    return (result);
}

int anybase_to_decimal(int nbr, char *base)
{
    int base_len;
    int result;
    int digit;

    digit = 0;
    result = 0;
    base_len = 0;
    while (base[base_len] != '\0')
        base_len++;
    while (nbr > 0)
    {
        result += (nbr % 10) * ft_pow(base_len, digit);
        nbr /= 10;
        digit++;
    }
    return (result);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int no_chill;

    no_chill = 0;
    if (nbr == -2147483648)
	{
		write(1, "-", 1);
		no_chill = 1;
		ft_putnbr(anybase_to_decimal(-(nbr / 10), base)); 
	}
    else if (nbr < 0)
    {
        write(1, "-", 1);
		ft_putnbr(anybase_to_decimal(-nbr, base));
    }
    else
    {
        ft_putnbr(anybase_to_decimal(nbr, base));
    }
    if (no_chill == 1)
    {
        write(1, "8", 1);
    }
}

int main(void)
{
    ft_putnbr_base(42, "0123456789");
}
