/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:33:56 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 10:50:26 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*buff;

	i = 0;
	while (tab[i + 1])
	{
		while (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buff = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buff;
			i = 0;
		}
		i++;
	}
}
