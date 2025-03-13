#include "ft_btree.h"

void	ft_biggest_branch(t_btree *root, int *max, int count)
{
	if (!root)
		return ;
	ft_biggest_branch(root->left, max, count + 1);
	ft_biggest_branch(root->right, max, count + 1);
	if (count > *max)
		*max = count;
}

int	btree_level_count(t_btree *root)
{
	int	max;

	if (!root)
		return (0);
	max = 1;
	ft_biggest_branch(root, &max, 1);
	return (max);
}
