#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_sep_words(char *str, char *charset)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, charset) && !in_word)
		{
			words++;
			in_word = 1;
		}
		else if (is_sep(*str, charset) && in_word)
			in_word = 0;
		str++;
	}
	return (words);
}

char	*retrieve_word(char *start, char *end)
{
	char	*ptr;
	int		i;

	ptr = malloc((sizeof(char) * (end - start)) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = *start++;
	ptr[i] = '\0';
	return (ptr);
}

char	*next_word_pointer(int i, char *str, char *charset)
{
	int		words;
	int		in_word;
	char	*start;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, charset) && !in_word)
		{
			words++;
			in_word = 1;
			start = str;
		}
		if ((is_sep(*str, charset) || *(str + 1) == '\0') && in_word)
		{
			in_word = 0;
			if (words - 1 == i && is_sep(*str, charset))
				return (retrieve_word(start, str));
			else if (words - 1 == i)
				return (retrieve_word(start, str + 1));
		}
		str++;
	}
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**solution;
	int		word_num;
	int		i;

	i = 0;
	word_num = ft_count_sep_words(str, charset);
	solution = malloc((sizeof(void *) * word_num) + 1);
	if (!solution)
		return (NULL);
	while (i < word_num)
	{
		solution[i] = next_word_pointer(i, str, charset);
		i++;
	}
	solution[i] = '\0';
	return (solution);
}

// #include <stdio.h>
// int main(void)
// {
//     char *str = " -Hola-:;;-:-mundo,esto;es-una:prueba;;;; ";
//     char *charset = "-,;:";
//     char **result = ft_split(str, charset);
//     for (int i = 0; result[i-1] != 0; i++)
// 	{
//         printf("result[%d]: \"%s\"\n", i, result[i]);
// 	}
// 	free (result);
//     return (0);
// }

// #include <stdio.h>
// int main(void)
// {
//     printf("Size of char: %zu bytes\n", sizeof(char));
//     printf("Size of int: %zu bytes\n", sizeof(int));
//     printf("Size of pointer: %zu bytes\n", sizeof(void *));
//     return 0;
// }

// int	count_sep_words(char *str, char *charset)
// {
// 	int		charset_len;
// 	int		words;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		l;
// 	charset_len = ft_strlen(charset);
// 	words = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		l = 0;
// 		while (j < charset_len)
// 		{
// 			if (str[i] == charset[j])
// 			{
// 				k = 0;
// 				l = 0;
// 				while (k < charset_len)
// 				{
// 					if (str[i + 1] != charset[k])
// 						l++;
// 					if (l == charset_len)
// 					{
// 						words++;
// 						l = 0;
// 					}
// 					k++;
// 				}
// 			}
// 			else if (i == 0)
// 				l++;
// 			if (l == charset_len)
// 			{
// 				words++;
// 				l = 0;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (words);
// }
