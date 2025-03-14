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
