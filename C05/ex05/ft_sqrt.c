/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:11:52 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/10 13:08:07 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int sqr;
	int value;

	sqr = 1;
	value = 1;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (value < nb && sqr < 46341)
	{
		value = sqr * sqr;
		if (value == nb)
			return (sqr);
		sqr++;
	}
	return (0);
}
