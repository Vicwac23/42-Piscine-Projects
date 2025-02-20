/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <victmore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:38:38 by victmore          #+#    #+#             */
/*   Updated: 2025/02/19 13:56:39 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define EMPTY_CHAR '.'
#define OBSTACLE_CHAR 'o'
#define FULL_CHAR 'x'

// Returns the length of a line until '\n'
int	line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

// Returns the number at the header as int
int	get_init_number(char *str, int len)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (i < len && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

// Checks lines length and characters
int	validate_lines(char *map, int line_count, int expected_len)
{
	int	lines;
	int	curr_len;

	lines = 0;
	while (*map && lines < line_count)
	{
		curr_len = 0;
		while (map[curr_len] && map[curr_len] != '\n')
		{
			if (map[curr_len] != EMPTY_CHAR
				&& map[curr_len] != OBSTACLE_CHAR && map[curr_len] != FULL_CHAR)
				return (0);
			curr_len++;
		}
		if (curr_len != expected_len)
			return (0);
		lines++;
		if (map[curr_len] == '\n')
			map += curr_len + 1;
		else
			map += curr_len;
	}
	return (lines == line_count);
}

// Where the validation is done
int	is_map_valid(char *map_data)
{
	int	header_len;
	int	line_count;
	int	expected_len;

	if (!map_data || map_data[0] == '\0' || map_data[0] == '0')
		return (-1);
	header_len = line_length(map_data);
	if (header_len < 4)
		return (-1);
	if (map_data[header_len - 3] != EMPTY_CHAR
		|| map_data[header_len - 2] != OBSTACLE_CHAR
		|| map_data[header_len - 1] != FULL_CHAR)
		return (-1);
	line_count = get_init_number(map_data, header_len - 3);
	if (line_count <= 0)
		return (-1);
	map_data += header_len + 1;
	expected_len = line_length(map_data);
	if (expected_len == 0)
		return (-1);
	if (validate_lines(map_data, line_count, expected_len) == 0)
		return (-1);
	return (0);
}
