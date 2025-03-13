#include <unistd.h>

void	str_write(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(char **argv, int argc)
{
	int	i;
	int	curr;

	i = 1;
	while (i < argc)
	{
		curr = i;
		while (curr > 1 && ft_strcmp(argv[curr - 1], argv[curr]) > 0)
		{
			ft_swap(&argv[curr], &argv[curr - 1]);
			curr--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		str_write(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
