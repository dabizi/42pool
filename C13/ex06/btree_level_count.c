/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:14:44 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 11:00:23 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		get_max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

int		btree_level_count(t_btree *root)
{
	int count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = get_max(count, btree_level_count(root->left));
	if (root->right)
		count = get_max(count, btree_level_count(root->right));
	return (count + 1);
}
