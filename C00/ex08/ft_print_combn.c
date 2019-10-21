/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:25:01 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/04 16:21:59 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int ischar, char c, int nb)
{
	if (ischar)
		write(1, &c, 1);
	else
	{
		if (nb >= 10)
			ft_print(0, '0', (nb / 10));
		ft_print(1, (nb % 10 + '0'), 0);
	}
}

int		ft_give_max(int n)
{
	int i;
	int j;
	int ten;
	int result;

	i = 0;
	j = 9;
	ten = 1;
	result = 0;
	while (i < n)
	{
		result += (j * ten);
		j--;
		ten *= 10;
		i++;
	}
	return (result);
}

void	display(int i, int max, int n)
{
	int cpy;
	int decimal;

	cpy = i;
	decimal = 1;
	while (cpy > 10)
	{
		decimal++;
		cpy /= 10;
	}
	n -= decimal;
	while (n > 0)
	{
		ft_print(1, '0', 0);
		n--;
	}
	ft_print(0, '0', i);
	if (i != max)
	{
		ft_print(1, ',', 0);
		ft_print(1, ' ', 0);
	}
}

int		ft_check_diff(int i)
{
	int temp;

	while (i >= 10)
	{
		temp = (i % 10);
		i /= 10;
		if (temp <= (i % 10))
			return (0);
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int i;
	int max;
	int temp;
	int last_digit;

	if (n == 1)
		write(1, "0, ", 3);
	i = 1;
	temp = n - 1;
	while (temp > 1)
	{
		last_digit = i % 10;
		i *= 10;
		last_digit++;
		i += last_digit;
		temp--;
	}
	max = ft_give_max(n);
	while (i <= max)
	{
		if (ft_check_diff(i))
			display(i, max, n);
		i++;
	}
}
