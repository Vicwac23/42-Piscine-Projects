#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

//write this definition in the ft_list.h
void	ft_print_link_list(t_list *begin_list)
{
	t_list	*temp;

	if (!begin_list)
		return ;
	temp = begin_list;
	while (temp)
	{
		printf("%s", (char *)temp->data);
		temp = temp->next;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}
