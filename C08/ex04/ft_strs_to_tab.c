/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:24:18 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/18 17:47:09 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	char		*cpy;
	int			i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int				index;
	t_stock_str		*tab;

	if (ac < 0 || !av)
		return (NULL);
	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	index = 0;
	while (index < ac)
	{
		if (!av[index])
		{
			while (index > 0)
				free(tab[--index].copy);
			free(tab);
			return (NULL);
		}
		tab[index].str = av[index];
		tab[index].size = ft_strlen(av[index]);
		if (!(tab[index].copy = ft_strdup(av[index])))
			return (NULL);
		index++;
	}
	tab[index].str = NULL;
	return (tab);
}
