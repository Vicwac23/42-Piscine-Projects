#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*temp;

	if (!begin_list)
		return (NULL);
	temp = begin_list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
