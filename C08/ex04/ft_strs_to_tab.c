#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

struct s_stock_str	ft_create_sstock(char *str)
{
	struct s_stock_str	temp;
	int					i;

	temp.size = ft_strlen(str);
	temp.str = str;
	temp.copy = malloc((sizeof(char) * temp.size) + 1);
	i = -1;
	while (str[++i])
	{
		temp.copy[i] = str[i];
	}
	temp.copy[i] = '\0';
	return (temp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*result;
	int					i;

	result = malloc((sizeof(struct s_stock_str) * (ac + 1)));
	i = -1;
	while (++i < ac)
		result[i] = ft_create_sstock(av[i]);
	result[i].size = 1;
	result[i].str = NULL;
	result[i].copy = NULL;
	return (result);
}
