/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:06:20 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 10:40:50 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_any(char **tab, int (*f)(char*))
{
	while (*tab != 0)
	{
		if (f(*(tab++)))
			return (1);
	}
	return (0);
}
