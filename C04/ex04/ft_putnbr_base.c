/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:55:59 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/11 19:49:37 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int length, char *base)
{
	long int nbr;

	nbr = (long int)nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= length)
		ft_putnbr(nbr / length, length, base);
	ft_putchar(base[nbr % length]);
}

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > 'z')
			return (0);
		if (str[i] > '9' && str[i] < 'A')
			return (0);
		if (str[i] > 'Z' && str[i] < 'a')
			return (0);
		i++;
	}
	return (1);
}

int		test(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!ft_str_is_alpha(base))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;

	if (base)
	{
		i = 0;
		while (base[i] != '\0')
			i++;
		if (i > 1)
		{
			if (test(base))
				ft_putnbr(nbr, i, base);
		}
	}
}
