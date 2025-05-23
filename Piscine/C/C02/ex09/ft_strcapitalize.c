char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		new_word;
	int		is_num;
	int		is_char;

	ptr = str;
	new_word = 1;
	while (*ptr)
	{
		is_num = *ptr >= '0' && *ptr <= '9';
		is_char = (*ptr | 32) >= 'a' && (*ptr | 32) <= 'z';
		if (is_num || is_char)
		{
			if (new_word && (*ptr >= 'a' && *ptr <= 'z'))
				*ptr = *ptr - 32;
			else if (!new_word && (*ptr >= 'A' && *ptr <= 'Z'))
				*ptr = *ptr + 32;
			new_word = 0;
		}
		else
			new_word = 1;
		ptr++;
	}
	return (str);
}
