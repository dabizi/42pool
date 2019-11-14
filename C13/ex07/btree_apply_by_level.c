/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:08:15 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 14:09:37 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	btree_level_count_extended(t_btree *root, int *top, int level)
{
	if (!root)
		return ;
	if (level > *top)
		*top = level;
	btree_level_count_extended(root->left, top, level + 1);
	btree_level_count_extended(root->right, top, level + 1);
}

int		btree_level_count2(t_btree *root)
{
	int top;

	if (!root)
		return (0);
	top = 0;
	btree_level_count_extended(root->left, &top, 2);
	btree_level_count_extended(root->right, &top, 2);
	return (top);
}

void	btree_apply(t_btree *root, int i, int *level, void (*applyf)
		(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (i == (*level % 1000))
	{
		(*applyf)(root->item, *level % 1000, *level > 1000);
		if (*level > 1000)
			*level -= 1000;
	}
	else
	{
		btree_apply(root->left, i + 1, level, applyf);
		btree_apply(root->right, i + 1, level, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int level;
	int index;

	if (root)
		(*applyf)(root->item, 0, 1);
	index = 0;
	while (index < btree_level_count2(root))
	{
		level = 1000 + index + 1;
		btree_apply(root, 0, &level, applyf);
		index++;
	}
}
