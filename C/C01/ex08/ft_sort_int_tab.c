/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:46:52 by victmore          #+#    #+#             */
/*   Updated: 2025/02/11 18:48:51 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
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
// int	main(void)
// {
// 	int	arr[] = {1,6,9,2,5,8,1,7,0,3,6,2};
// 	ft_sort_int_tab(arr, 12);
// 	return (0);
// }