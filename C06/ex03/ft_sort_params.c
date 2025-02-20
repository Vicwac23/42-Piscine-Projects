/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:34:52 by victmore          #+#    #+#             */
/*   Updated: 2025/02/19 19:33:12 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(int *argv, int argc)
{
	int	i;
	int	curr;

	i = 0;
	while (i < size)
	{
		curr = i;
		while (curr > 0 && tab[curr] > tab[curr - 1])
		{
			ft_swap(&tab[curr], &tab[curr - 1]);
			curr--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv, argc - 1);
	i = 1;
	while (i < argc)
	{
		str_write(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
