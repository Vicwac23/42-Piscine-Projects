#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*compose_new_arr(int size, char **strs, char *sep, char *result)
{
	int		i;
	int		j;
	int		curr;

	curr = 0;
	j = -1;
	while (++j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			result[curr] = strs[j][i];
			i++;
			curr++;
		}
		i = 0;
		while (sep[i] && j + 1 < size)
		{
			result[curr] = sep[i];
			i++;
			curr++;
		}
	}
	result[curr] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		j;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	j = -1;
	i = 0;
	while (++j < size)
		i += ft_strlen(strs[j]);
	i += ft_strlen(sep) * (size - 1);
	result = malloc((sizeof(char) * i) + 1);
	if (!result)
		return (NULL);
	result = compose_new_arr(size, strs, sep, result);
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*(words[]) = {"Hola", "buenos", "dias"};
// 	char	sep[] = " -+- "; 
// 	char	*new = ft_strjoin(3, words, sep);
// 	printf("%s", new);
// 	free(new);
// }
