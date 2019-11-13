/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:18:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 17:51:46 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*before;

	list = *begin_list;
	while (list && list->next)
	{
		if ((*cmp)(list->next->data, data_ref) == 0)
		{
			before = list->next;
			list->next = list->next->next;
			free_fct(before->data);
			free(before);
		}
		list = list->next;
	}
	list = *begin_list;
	if (list && (*cmp)(list->data, data_ref) == 0)
	{
		*begin_list = list->next;
		free_fct(list->data);
		free(list);
	}
}
