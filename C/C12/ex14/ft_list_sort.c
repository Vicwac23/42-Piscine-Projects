#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*temp;

	if (!begin_list || !(*begin_list))
		return ;
	temp = *begin_list;
}
