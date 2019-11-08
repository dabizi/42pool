/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:09:30 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 14:41:27 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <unistd.h>

void	nofile_error(char *av0, char *arg)
{
	ft_putstr_error(av0);
	ft_putstr_error(": ");
	ft_putstr_error(arg);
	ft_putstr_error(": No such file or directory\n");
}

void	permission_error(char *av0, char *arg)
{
	ft_putstr_error(av0);
	ft_putstr_error(": ");
	ft_putstr_error(arg);
	ft_putstr_error(": Permission denied\n");
}

void	directory_error(char **av)
{
	ft_putstr_error(basename(av[0]));
	ft_putstr_error(": stdin: Is a directory\n");
}

int		already_printed(int error)
{
	static int	printed;

	if (error == 0)
		printed = 1;
	return (printed);
}

int		ft_error(char *av0, int ac, char *arg)
{
	if (errno == EACCES)
	{
		permission_error(av0, arg);
		return (1);
	}
	if (errno == EISDIR)
	{
		if (ac > 4)
		{
			if (already_printed(999))
				write(1, "\n==> ", 5);
			else
				write(1, "==> ", 4);
			ft_putstr_error(arg);
			write(1, " <==\n", 5);
			return (0);
		}
	}
	if (errno == ENOENT)
	{
		nofile_error(av0, arg);
		return (1);
	}
	return (0);
}
