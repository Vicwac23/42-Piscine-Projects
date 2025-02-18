/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:21:49 by victmore          #+#    #+#             */
/*   Updated: 2025/02/04 10:58:48 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cont;
	char			*ptr;

	ptr = dest;
	cont = 0;
	while (cont < n)
	{
		if (*src != '\0')
		{
			*dest = *src;
			src++;
			dest++;
		}
		else
		{
			*dest = '\0';
			dest++;
		}
		cont++;
	}
	return (ptr);
}
