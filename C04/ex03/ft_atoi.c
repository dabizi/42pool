/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:42:29 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 11:32:03 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_getsize(char *str, int i)
{
	int size;

	size = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

int		iswhitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	else
		return (0);
}

int		ft_getresult(char *str, int i, int size)
{
	int j;
	int result;

	result = 0;
	j = 0;
	while (j < size)
	{
		result += str[i] - '0';
		if (j + 1 != size)
			result *= 10;
		j++;
		i++;
	}
	return (result);
}

int		ft_atoi(char *str)
{
	int i;
	int is_pos;
	int size;
	int result;

	i = 0;
	is_pos = 1;
	result = 0;
	size = 0;
	while (str[i] != '\0' && iswhitespace(str[i]))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			is_pos *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	size = ft_getsize(str, i);
	result = ft_getresult(str, i, size);
	return (result * is_pos);
}
