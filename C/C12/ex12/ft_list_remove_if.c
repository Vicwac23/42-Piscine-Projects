#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*ptr;
	t_list	*next;

	if (!begin_list || !(*begin_list))
		return ;
	prev = NULL;
	ptr = *begin_list;
	while (ptr)
	{
		next = ptr->next;
		if ((*cmp)(ptr->data, data_ref) == 0)
		{
			if (prev && next)
				prev->next = next;
			(*free_fct)(ptr->data);
			free(ptr);
		}
		else
			prev = ptr;
		ptr = next;
	}
}
