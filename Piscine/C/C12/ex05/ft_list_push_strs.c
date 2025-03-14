#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*new_elem;
	t_list	*first;
	int		i;

	if (size <= 0)
		return (NULL);
	first = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		new_elem = ft_create_elem(strs[i]);
		new_elem->next = first;
		first = new_elem;
		i++;
	}
	return (first);
}

// int	main(void)
// {
// 	char	*strs[] = {"yuru camp", "frieren", "himmel the hero"};
// 	t_list	*my_list;
// 	my_list = ft_list_push_strs(5, strs);
// 	ft_print_link_list(my_list);
// }
