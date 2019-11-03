/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:49:33 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/18 19:40:33 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			test_base(char *base);
int			test_char(char c);
int			value_char(char c, char *base);
int			ft_neg(int neg, char c);

int			ft_size_nbr(long nb, char *base)
{
	int		len;
	int		base_len;

	base_len = 0;
	len = 0;
	if (nb < 0)
		nb = -nb;
	while (base[base_len])
		base_len++;
	while (nb >= base_len)
	{
		len++;
		nb /= base_len;
	}
	return (++len);
}

char		*ft_itoa(long nb, int len, char *base, int length_base)
{
	int		neg;
	char	*result;

	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	if (!(result = (char *)malloc(sizeof(char) * len + neg)))
		return (NULL);
	result[len + neg - 1] = '\0';
	while (len > neg)
	{
		result[len + neg - 2] = base[nb % length_base];
		nb = nb / length_base;
		len--;
	}
	if (neg == 1)
		result[0] = '-';
	return (result);
}

long		ft_atoi_base(char *str, char *base)
{
	long	result;
	int		neg;
	int		ba;
	int		i;

	i = 0;
	result = 0;
	neg = 1;
	ba = test_base(base);
	while (test_char(str[i]) == 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		neg = ft_neg(neg, str[i]);
		i++;
	}
	while (str[i] && (test_char(str[i]) == 1))
	{
		if (value_char(str[i], base) == -1)
			return (result * neg);
		result = result * ba + value_char(str[i], base);
		i++;
	}
	return (result * neg);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	temp;
	int		bsize;
	int		size_nb;
	char	*result;

	if (nbr == NULL)
		return (NULL);
	if ((!nbr) || !(base_from) || !(base_to))
		return (NULL);
	if (test_base(base_from) < 2 || test_base(base_to) < 2)
		return (NULL);
	bsize = 0;
	temp = ft_atoi_base(nbr, base_from);
	size_nb = ft_size_nbr(temp, base_to) + 1;
	if (temp < 0)
		temp = -temp;
	while (base_to[bsize])
		bsize++;
	temp = ft_atoi_base(nbr, base_from);
	result = ft_itoa(temp, size_nb, base_to, bsize);
	return (result);
}
