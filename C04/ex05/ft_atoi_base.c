/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:59:30 by victmore          #+#    #+#             */
/*   Updated: 2025/02/17 15:08:24 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// EL PROBLEMA CON EL ATOI ES QUE CUANDO LE DAS UN NUMERO QUE NO PERTENECE A LA BASE DADA SIMPLEMENTE ESCRIBE '0'
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
	int	i;

	base_len = 0;
	if (!is_valid_base(base))
		return (0);
	while (base[base_len] != '\0')
		base_len++;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	str_len = 0;
	while (str[i + str_len] && get_index(str[i + str_len], base) != -1)
		str_len++;
	return (sign * ft_atoi_recursive(str, base, base_len, str_len - 1));
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	temp;
// 	temp = ft_atoi_base("pona", "poniguay");
// 	printf("%d", temp);
// 	return (0);
// }
