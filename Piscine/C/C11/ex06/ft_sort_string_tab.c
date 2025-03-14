int	ft_strcmp(char *a, char *b)
{
	while (*a && (*a == *b))
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = i;
		while (j > 0 && (ft_strcmp(tab[j], tab[j - 1]) < 0))
		{
			ft_swap(&tab[j], &tab[j - 1]);
			j--;
		}
		i++;
	}
}

//#include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	char	*tab[] = {"banana", "apple", "cherry", "date", "elderberry", NULL};
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	ft_sort_string_tab(tab);
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s ", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }