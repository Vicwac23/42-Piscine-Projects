#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*temp;

	if (!begin_list1 || !begin_list2)
		return ;
	if (!(*begin_list1))
		(*begin_list1) = begin_list2;
	temp = *begin_list1;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = begin_list2;
}
