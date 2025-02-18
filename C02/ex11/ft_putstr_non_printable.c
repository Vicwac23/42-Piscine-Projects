/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:24:15 by victmore          #+#    #+#             */
/*   Updated: 2025/02/16 18:36:32 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	c_to_hex(char c)
{
	char	*hex_vals;

	hex_vals = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex_vals[(c >> 4) & 0xF], 1);
	write(1, &hex_vals[c & 0xF], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str >= 0 && *str <= 31) || *str == 127)
			c_to_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
