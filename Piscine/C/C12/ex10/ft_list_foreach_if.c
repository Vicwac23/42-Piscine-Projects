#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
	t_list	*temp;

	if (!begin_list)
		return ;
	temp = begin_list;
	while (temp)
	{
		if ((*cmp)(temp->data, data_ref) == 0)
		{
			(*f)(temp->data);
		}
		temp = temp->next;
	}
}
