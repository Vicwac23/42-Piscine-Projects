#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	in_word;
	int	i;
	int	words;

	in_word = 0;
	i = 0;
	words = 0;
	while (str[i])
	{
		if (!in_word && !is_sep(str[i], charset))
		{
			in_word = 1;
			words++;
		}
		else if (in_word && is_sep(str[i], charset))
		{
			in_word = 0;
		}
		i++;
	}
	return (words);
}

char	*word_malloc(char *start, char *end)
{
	char	*ptr;
	int		len;
	int		i;

	len = end - start + 1;
	ptr = malloc((sizeof(char) * len) + 1);
	i = 0;
	while (i < len)
	{
		ptr[i] = start[i];
		i++;
	}
	return (ptr);
}

char	*get_word_in_index(char *str, char *charset, int index)
{
	char	*start;
	int		in_word;
	int		words;

	in_word = 0;
	words = 0;
	while (str)
	{
		if (!in_word && !is_sep(*str, charset))
		{
			words++;
			start = str;
			in_word = 1;
		}
		if (in_word && (is_sep(*str, charset) || *(str + 1) == '\0'))
		{
			in_word = 0;
			if ((words - 1 == index) && (*(str + 1) == '\0'))
				return (word_malloc(start, str));
			else if (words - 1 == index)
				return (word_malloc(start, str - 1));
		}
		str++;
	}
	return ('\0');
}

char	**ft_split(char *str, char *charset)
{
	char	**sol;
	int		words;
	int		i;

	words = count_words(str, charset);
	sol = malloc(sizeof(char *) * words);
	i = 0;
	while (i < words)
	{
		sol[i] = get_word_in_index(str, charset, i);
		i++;
	}
	sol[i] = '\0';
	return (sol);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = " -Hola-:;;-:-mundo,esto;es-una:prueba;;;; - vic 	";
// 	char *charset = "-,;:";
// 	char **result = ft_split(str, charset);
// 	for (int i = 0; result[i - 1] != 0; i++)
// 	{
// 		printf("result[%d]: \"%s\"\n", i, result[i]);
// 	}
// 	free (result);
//     return (0);
// }
