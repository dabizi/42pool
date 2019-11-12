/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:24:25 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 10:43:24 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if (f(tab[i]))
			result++;
		i++;
	}
	return (result);
}
