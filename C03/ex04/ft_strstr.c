/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:14:41 by victmore          #+#    #+#             */
/*   Updated: 2025/02/13 10:08:35 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
// void	ft_putstr(char *str)
// {
// 	while (*str != '\0')
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }
// int	main(void)
// {
// 	char	str[]="holaslaks";
// 	char	find[]="lak";
// 	ft_putstr(ft_strstr(str, find));
// }