/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:53:21 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/18 19:15:57 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test_char(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v')
		return (0);
	else if (c > ' ' || c <= '~')
		return (1);
	else
		return (-1);
}

int		test_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || (test_char(base[i]) == 0))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		value_char(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_neg(int neg, char c)
{
	if (c == '-')
		return (-neg);
	else
		return (neg);
}
