char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0' && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	arr[] = "hola";
// 	char	arr2[] = "holb";
// 	printf("%s", ft_strncat(arr, arr2, 2));
// 	return (0);
// }