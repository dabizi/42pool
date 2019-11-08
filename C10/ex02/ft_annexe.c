/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:10:09 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 17:59:33 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_tail.h"
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int		is_pos;
	int		result;

	is_pos = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		is_pos *= *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (is_pos * result);
}

void	read_stdin(char **av)
{
	char	*buff;
	char	c;
	int		bytes;
	int		r;
	int		i;

	bytes = ft_atoi(av[2]);
	if (bytes == 0 && errno != EISDIR)
	{
		while ((r = read(0, &c, 1)) && c != EOF)
			;
		return ;
	}
	if (!(buff = malloc(sizeof(char) * bytes)))
		return ;
	i = 0;
	while ((r = read(0, buff + i % bytes, 1)) &&
			buff[i % bytes] != EOF)
		i++;
	if (errno == EISDIR)
		return (directory_error(av));
	if (i >= bytes)
		write(1, buff + i % bytes, bytes - i % bytes);
	write(1, buff, i % bytes);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}
