/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:07:37 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 18:22:51 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size2(t_list *begin_list)
{
	int		size;
	t_list	*a;

	size = 0;
	a = begin_list;
	while (a)
	{
		a = a->next;
		size++;
	}
	return (size);
}

t_list	*ft_list_at2(t_list *begin_list, unsigned int nb)
{
	unsigned int	i;
	t_list			*list;

	list = begin_list;
	if (!list)
		return (0);
	i = 0;
	while (i < nb)
	{
		if (list->next)
			list = list->next;
		else
			return (0);
		i++;
	}
	return (list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	void	*tmp;
	int		i;
	int		size;

	if (begin_list == 0)
		return ;
	i = 0;
	size = ft_list_size2(begin_list) - 1;
	while (i <= size / 2)
	{
		tmp = ft_list_at2(begin_list, i)->data;
		ft_list_at2(begin_list, i)->data =
			ft_list_at2(begin_list, size - i)->data;
		ft_list_at2(begin_list, size - i)->data = tmp;
		i++;
	}
}
