/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:49:03 by victmore          #+#    #+#             */
/*   Updated: 2025/02/18 18:42:29 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

char	*ft_realloc(char *buffer, int total_size, int *capacity)
{
	char	*new_buffer;
	int		i;

	*capacity *= 2;
	new_buffer = malloc(*capacity);
	if (!new_buffer)
		return (NULL);
	i = -1;
	while (++i < total_size)
		new_buffer[i] = buffer[i];
	free(buffer);
	buffer = new_buffer;
	return (buffer);
}

char	*ft_file_to_buffer(int fd, char *buffer, int *capacity)
{
	int		bytes_read;
	int		total_size;

	total_size = 0;
	bytes_read = read(fd, buffer + total_size, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		total_size += bytes_read;
		if (total_size + BUFFER_SIZE + 1 >= *capacity)
		{
			buffer = ft_realloc(buffer, total_size, capacity);
			if (!buffer)
				return (NULL);
		}
		bytes_read = read(fd, buffer + total_size, BUFFER_SIZE);
	}
	buffer[total_size] = '\0';
	return (buffer);
}

char	*ft_open_read_file(char *filename)
{
	int		file_descriptor;
	int		capacity;
	char	*buffer;

	capacity = BUFFER_SIZE;
	buffer = malloc(capacity);
	if (!buffer)
		return (NULL);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (free(buffer), NULL);
	buffer = ft_file_to_buffer(file_descriptor, buffer, &capacity);
	close(file_descriptor);
	return (buffer);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		char *map_data = ft_open_read_file(argv[1]);
// 		if (map_data)
// 		{
// 			printf("%s", map_data);
// 			free(map_data);
// 		}
// 	}
// 	return (0);
// }
