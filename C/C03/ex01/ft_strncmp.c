/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:25:56 by victmore          #+#    #+#             */
/*   Updated: 2025/02/16 13:29:55 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	arr[] = "hola";
// 	char	arr2[] = "holb";
// 	int	temp;
// 	temp = ft_strncmp(arr, arr2, 3);
// 	printf("%d", temp);
// 	return (0);
// }