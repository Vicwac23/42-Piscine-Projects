#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		size;

	size = 0;
	temp = begin_list;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	ft_swap_data(void **back, void **front)
{
	void	*temp;

	temp = *back;
	*back = *front;
	*front = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*back;
	t_list	*front;
	int		size;
	int		count;
	int		i;

	count = 0;
	size = ft_list_size(begin_list);
	back = begin_list;
	front = begin_list;
	while (count < size / 2)
	{
		i = count - 1;
		while (++i < size - 1 - (count * 2))
			front = front->next;
		ft_swap_data(&back->data, &front->data);
		back = back->next;
		front = back;
		count++;
	}
}
