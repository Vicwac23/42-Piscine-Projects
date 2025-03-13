char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cont;
	char			*ptr;

	ptr = dest;
	cont = 0;
	while (cont < n)
	{
		if (*src != '\0')
		{
			*dest = *src;
			src++;
			dest++;
		}
		else
		{
			*dest = '\0';
			dest++;
		}
		cont++;
	}
	return (ptr);
}
