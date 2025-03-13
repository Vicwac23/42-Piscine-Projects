char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0')
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
// 	printf("%s", ft_strcat(arr, arr2));
// 	return (0);
// }