/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:37:19 by victmore          #+#    #+#             */
/*   Updated: 2025/02/19 15:37:43 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_open_read_file(char *filename);
int		is_map_valid(char *map_data);
void	write_map(char *map_data);

int	main(int argc, char **argv)
{
	int		i;
	char	*map_data;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			map_data = ft_open_read_file(argv[i]);
			if (!map_data || is_map_valid(map_data) == -1)
			{
				write(1, "map error\n", 10);
			}
			else if (map_data)
			{
				write_map(map_data);
				free(map_data);
			}
			i++;
		}
	}
	return (0);
}