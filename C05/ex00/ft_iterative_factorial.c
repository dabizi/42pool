/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:55:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/08 11:25:15 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int stop;

	i = 2;
	stop = nb;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	while (i < stop)
	{
		nb *= i;
		i++;
	}
	return (nb);
}
