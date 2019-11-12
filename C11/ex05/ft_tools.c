/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:10:05 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 12:31:32 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	long nb;

	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}

int		ft_atoi(char *str)
{
	int is_pos;
	int res;

	is_pos = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		is_pos *= *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * is_pos);
}

int		ft_strcmp(char *str, char const *str2)
{
	int i;

	i = 0;
	while (str[i] && str[i] == str2[i])
		i++;
	return (str[i] - str2[i]);
}
