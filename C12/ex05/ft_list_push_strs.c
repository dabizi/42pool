/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:29:18 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/25 17:44:35 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		index;
	t_list	*list;
	t_list	*new_param;

	index = 0;
	list = 0;
	while (index < size)
	{
		new_param = ft_create_elem(strs[index]);
		new_param->next = list;
		list = new_param;
		index++;
	}
	return (list);
}
