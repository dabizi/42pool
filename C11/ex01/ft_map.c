/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:30:57 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 14:18:12 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	i = 0;
	if (!(result = (int*)malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
