/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:10:50 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 17:48:00 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *buff;
	t_list *buff2;
	t_list *list;

	list = *begin_list;
	if (!list || !(list->next))
		return ;
	buff = list->next;
	buff2 = buff->next;
	list->next = 0;
	buff->next = list;
	while (buff2)
	{
		list = buff;
		buff = buff2;
		buff2 = buff2->next;
		buff->next = list;
	}
	*begin_list = buff;
}
