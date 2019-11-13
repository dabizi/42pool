/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:55:32 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 17:53:50 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*a;
	t_list		*b;
	t_list		*buff;

	a = *begin_list;
	while (a)
	{
		b = *begin_list;
		while (b->next)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
			{
				buff = b->data;
				b->data = b->next->data;
				b->next->data = buff;
			}
			b = b->next;
		}
		a = a->next;
	}
}
