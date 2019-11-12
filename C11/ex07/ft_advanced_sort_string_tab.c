/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:34:52 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 10:49:30 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*buff;

	i = 0;
	while (tab[i + 1])
	{
		while (cmp(tab[i], tab[i + 1]) > 0)
		{
			buff = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buff;
			i = 0;
		}
		i++;
	}
}
