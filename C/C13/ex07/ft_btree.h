#ifndef FT_BTREE_H

# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

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

typedef struct s_level
{
	int	max;
	int	first;
}	t_level;

t_level	*t_level_create(int max, int first)
{
	t_level	*temp;

	temp = (t_level *)malloc(sizeof(t_level));
	if (!temp)
		return (NULL);
	temp->first = first;
	temp->max = max;
	return (temp);
}

#endif