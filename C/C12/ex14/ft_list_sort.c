#include "ft_list.h"

int	is_sorted(t_list *begin_list, int (*cmp)())
{
	t_list	*temp;
	t_list	*next;

	temp = begin_list;
	while (temp->next)
	{
		next = temp->next;
		if ((*cmp)(temp->data, next->data) > 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_swap_node(t_list **begin_list, t_list *prev,
	t_list *curr, t_list *next)
{
	if (prev)
		prev->next = next;
	else
		*begin_list = next;
	curr->next = next->next;
	next->next = curr;
}

void	ft_sort_pass(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	curr = *begin_list;
	while (curr && curr->next)
	{
		next = curr->next;
		if ((*cmp)(curr->data, next->data) > 0)
		{
			ft_swap_node(begin_list, prev, curr, next);
			prev = next;
		}
		else
		{
			prev = curr;
			curr = next;
		}
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	if (!begin_list || !(*begin_list) || !(*begin_list)->next)
		return ;
	while (!is_sorted(*begin_list, cmp))
		ft_sort_pass(begin_list, cmp);
}
