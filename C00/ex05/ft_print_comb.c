/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:11:21 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/04 09:04:18 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char i, char j, char l)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &l, 1);
	if (i != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char l;

	i = '0';
	j = '1';
	l = '2';
	while (i < '8')
	{
		while (j < '9')
		{
			while (l < '9' + 1)
			{
				ft_putchar(i, j, l);
				l++;
			}
			j++;
			l = j + 1;
		}
		i++;
		j = i;
	}
}
