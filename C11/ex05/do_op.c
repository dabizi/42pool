/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:59:04 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 14:05:40 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include "ft_optab.h"
#include <unistd.h>

void	do_op(int a, int b, char *op)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = sizeof(g_optab) / sizeof(g_optab[0]);
	while (i < len)
	{
		if (ft_strcmp(op, g_optab[i].oper) == 0)
		{
			g_optab[i].f(a, b);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	ft_putnbr(0);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int a;
	int b;

	if (ac != 4)
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	do_op(a, b, av[2]);
	return (0);
}
