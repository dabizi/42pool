/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:51:57 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/12 15:43:40 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strstr(char *str, char to_find)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strlen(char *base, char *str, int i)
{
	int size;

	size = 0;
	while (str[i] != '\0' && ft_strstr(base, str[i]) != -1)
	{
		i++;
		size++;
	}
	return (size);
}

int		ft_getresult(char *str, char *base, int i, int base_length)
{
	int j;
	int result;
	int size;

	size = ft_strlen(base, str, i);
	result = 0;
	j = 0;
	while (j < size)
	{
		if (ft_strstr(base, str[i]) != -1)
			result += ft_strstr(base, str[i]);
		else
			return (result);
		if (j + 1 != size)
			result *= base_length;
		j++;
		i++;
	}
	return (result);
}

int		test(char *base)
{
	int i;
	int j;

	if (!base)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '\f' ||
			base[i] == '\n' || base[i] == '\r' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '-' || base[i] == '+')
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
	if (i < 2)
		return (0);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int is_pos;
	int result;
	int base_length;

	i = 0;
	is_pos = 1;
	result = 0;
	base_length = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f'
				|| str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\t' || str[i] == '\v'))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			is_pos *= -1;
		i++;
	}
	if (ft_strstr(base, str[i]) == -1)
		return (0);
	if (!(base_length = test(base)))
		return (0);
	result = ft_getresult(str, base, i, base_length);
	return (result * is_pos);
}
