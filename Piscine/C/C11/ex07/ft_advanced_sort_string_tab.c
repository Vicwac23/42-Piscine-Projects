void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = i;
		while ((j > 0) && (cmp(tab[j], tab[j - 1]) > 0))
		{
			ft_swap(&tab[j], &tab[j - 1]);
			j--;
		}
		i++;
	}
}

// int	ft_strcmp_by_numer_of_a(char *a, char *b)
// {
// 	int	counta;
// 	int	countb;
// 	counta = 0;
// 	countb = 0;
// 	while (*a)
// 	{
// 		if (*a == 'a')
// 			counta++;
// 		a++;
// 	}
// 	while (*b)
// 	{
// 		if (*b == 'a')
// 			countb++;
// 		b++;
// 	}
// 	return (counta - countb);
// }
// #include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	char	*tab[] = {"banana", "aaaa", "calderbarry", "ba", NULL};
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_advanced_sort_string_tab(tab, &ft_strcmp_by_numer_of_a);
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s ", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }