#include "ft_btree.h"

// Izq --> Root --> Der
void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*result;

	if (!root)
		return (NULL);
	result = btree_search_item(root->left, data_ref, cmpf);
	if (result)
		return (result);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}

// if (!root)
// 	return (NULL);
// if (cmpf(data_ref, root->item) < 0)
// {
// 	return(btree_search_item(root->left, data_ref, cmpf));
// }
// else if (cmpf(data_ref, root->item) > 0)
// {
// 	return (btree_search_item(root->right, data_ref, cmpf));
// }
// else
// {
// 	return (root->item);
// }