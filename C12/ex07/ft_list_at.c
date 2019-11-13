/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:07:24 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 17:46:33 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	index;
	t_list			*list;

	list = begin_list;
	if (!list)
		return (0);
	index = 0;
	while (index < nbr)
	{
		if (list->next)
			list = list->next;
		else
			return (0);
		index++;
	}
	return (list);
}
