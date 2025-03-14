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

void	ft_apply_fun_to_level(t_btree *root, t_level *level, int count,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (count == level->max)
	{
		applyf(root->item, count, level->first);
		level->first = 0;
		return ;
	}
	ft_apply_fun_to_level(root->left, level, count + 1, applyf);
	ft_apply_fun_to_level(root->right, level, count + 1, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)
	(void *item, int current_level, int is_first_elem))
{
	t_level	*level;
	int		size;

	if (!root || !applyf)
		return ;
	level = t_level_create(0, 0);
	if (!level)
		return ;
	size = 1;
	ft_biggest_branch(root, &size, 1);
	while (level->max < size)
	{
		level->first = 1;
		ft_apply_fun_to_level(root, level, 0, applyf);
		level->max++;
	}
	free(level);
}
