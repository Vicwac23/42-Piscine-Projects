#include "ft_list.h"

void	ft_add_to_tail(t_list **tail, t_list **left,
	t_list **right, int (*cmp)())
{
	if (cmp((*left)->data, (*right)->data) <= 0)
	{
		(*tail)->next = (*left);
		(*left) = (*left)->next;
	}
	else
	{
		(*tail)->next = (*right);
		(*right) = (*right)->next;
	}
	(*tail) = (*tail)->next;
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*left;
	t_list	*right;
	t_list	dummy;
	t_list	*tail;

	tail = &dummy;
	dummy.next = NULL;
	left = (*begin_list1);
	right = begin_list2;
	while (left && right)
		ft_add_to_tail(&tail, &left, &right, cmp);
	if (left)
		tail->next = left;
	else
		tail->next = right;
	*begin_list1 = dummy.next;
}
