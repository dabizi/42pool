/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:18:32 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 17:59:09 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_read(int file, char *buff)
{
	int r;

	while ((r = read(file, buff, BUFFER_SIZE)))
	{
		buff[r] = '\0';
		ft_putstr(buff);
	}
}

int		ft_error(char *av0, char *arg)
{
	if (errno == EACCES)
	{
		ft_putstr(av0);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Permission denied\n");
		return (1);
	}
	if (errno == EISDIR)
	{
		ft_putstr(av0);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": Is a directory\n");
		return (1);
	}
	if (errno == ENOENT)
	{
		ft_putstr(av0);
		ft_putstr(": ");
		ft_putstr(arg);
		ft_putstr(": No such file or directory\n");
		return (1);
	}
	return (0);
}

void	ft_cat(void)
{
	int		r;
	char	buff[BUFFER_SIZE + 1];

	r = 0;
	while ((r = read(0, buff, BUFFER_SIZE)))
	{
		buff[r] = '\0';
		ft_putstr(buff);
	}
}

void	ft_display(char *av0, char *arg)
{
	int		file;
	char	buff[BUFFER_SIZE + 1];

	errno = 0;
	file = open(arg, O_RDWR);
	if (file == -1)
	{
		if (arg[0] == '-' && arg[1] == '\0')
			ft_cat();
		else
			ft_error(av0, arg);
	}
	else
		ft_read(file, buff);
	if (close(file) == -1)
		ft_putstr("");
}

int		main(int ac, char *av[])
{
	int i;

	i = 1;
	if (ac < 2)
		ft_cat();
	else
	{
		while (i < ac)
		{
			ft_display(basename(av[0]), av[i]);
			i++;
		}
	}
	return (0);
}
