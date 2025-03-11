#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;
	t_list	*new_elem;

	if (!begin_list)
		return ;
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (!(*begin_list))
	{
		*begin_list = new_elem;
		return ;
	}
	temp = *begin_list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem;
}
