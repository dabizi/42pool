/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:22:58 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 18:24:29 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	void	*buff;

	if (begin_list == 0 || (list = *begin_list) == 0)
		return ;
	while (list->next)
	{
		while (cmp(list->data, list->next->data) > 0)
		{
			buff = list->data;
			list->data = list->next->data;
			list->next->data = buff;
			list = *begin_list;
		}
		list = list->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list *list;

	if (begin_list1 == 0)
	{
		begin_list1 = &begin_list2;
		return ;
	}
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		ft_list_sort2(begin_list1, cmp);
		return ;
	}
	list = *begin_list1;
	while (list->next)
		list = list->next;
	list->next = begin_list2;
	ft_list_sort2(begin_list1, cmp);
}
