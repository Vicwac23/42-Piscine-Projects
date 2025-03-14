#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*temp;

	temp = (t_btree *)malloc(sizeof(t_btree));
	if (!temp)
		return (NULL);
	temp->left = NULL;
	temp->right = NULL;
	temp->item = item;
	return (temp);
}
