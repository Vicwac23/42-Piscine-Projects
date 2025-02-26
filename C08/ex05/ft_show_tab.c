#include "ft_stock_str.h"
#include <unistd.h>

void	ft_write_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	show_nbr_recursive(int nbr)
{
	char	temp;

	temp = nbr % 10 + '0';
	if (nbr > 9)
		show_nbr_recursive(nbr / 10);
	write(1, &temp, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = -1;
	while (par[++i].str != NULL)
	{
		ft_write_str(par[i].str);
		show_nbr_recursive(par[i].size);
		write(1, "\n", 1);
		ft_write_str(par[i].copy);
	}
}

// #include <stdlib.h>

// int	ft_strlen(char *str)
// {
// 	int	len;
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }
// struct s_stock_str	ft_create_sstock(char *str)
// {
// 	struct s_stock_str	temp;
// 	int					i;
// 	temp.size = ft_strlen(str);
// 	temp.str = str;
// 	temp.copy = malloc((sizeof(char) * temp.size) + 1);
// 	i = -1;
// 	while (str[++i])
// 	{
// 		temp.copy[i] = str[i];
// 	}
// 	temp.copy[i] = '\0';
// 	return (temp);
// }
// struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// {
// 	struct s_stock_str	*result;
// 	int					i;
// 	result = malloc((sizeof(struct s_stock_str) * (ac + 1)));
// 	i = -1;
// 	while (++i < ac)
// 		result[i] = ft_create_sstock(av[i]);
// 	result[i].size = 1;
// 	result[i].str = NULL;
// 	result[i].copy = NULL;
// 	return (result);
// }
// int	main(void)
// {
// 	char *words[] = {"Hola", "muy", "buenas", "GG EZ"};
// 	struct s_stock_str	*gg = ft_strs_to_tab(4, words);
// 	ft_show_tab(gg);
// 	free(gg);
// }
