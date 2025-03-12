#include "ft_list.h"

void	ft_insert_elem(t_list **begin_list, t_list *prev,
	t_list *curr, t_list *new_elem)
{
	if (prev)
		prev->next = new_elem;
	else
		*begin_list = new_elem;
	new_elem->next = curr;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;
	t_list	*new_elem;

	if (!begin_list)
		return ;
	new_elem = ft_create_elem(data);
	if (!(*begin_list))
	{
		*begin_list = new_elem;
		return ;
	}
	prev = NULL;
	curr = *begin_list;
	while (curr && ((*cmp)(new_elem->data, curr->data) > 0))
	{
		prev = curr;
		curr = curr->next;
	}
	ft_insert_elem(begin_list, prev, curr, new_elem);
}
