/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:02:43 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 18:00:19 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	display_title(int i, int ac, char **av)
{
	int			j;
	static int	fail;

	fail = 0;
	j = 0;
	if (ac > 4)
	{
		if (already_printed(999))
			write(1, "\n==> ", 5);
		else
			write(1, "==> ", 4);
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, " <==\n", 5);
	}
}

int		filesz(int i, char **av)
{
	char	buff;
	int		size;
	int		file;

	size = 0;
	file = open(av[i], O_RDONLY);
	while (read(file, &buff, 1))
		size++;
	close(file);
	return (size);
}

void	display_content(int i, int file, int ac, char **av)
{
	long	bit;
	int		count;
	int		size;
	char	buff;

	size = filesz(i, av);
	count = 0;
	bit = ft_atoi(av[2]);
	display_title(i, ac, av);
	if (av[2][0] == '+')
	{
		while (count != bit - 1)
			count += read(file, &buff, 1);
		while (read(file, &buff, 1))
			write(1, &buff, 1);
	}
	else
	{
		while (count < (size - bit))
			count += read(file, &buff, 1);
		while (read(file, &buff, 1))
			write(1, &buff, 1);
	}
}

int		main(int ac, char **av)
{
	int		file;
	int		i;
	int		error;

	if (ac < (i = 3))
		return (-1);
	if (ac == 3)
		read_stdin(av);
	while (i < ac)
	{
		file = open(av[i], O_RDWR);
		error = ft_error(basename(av[0]), ac, av[i]);
		if (file >= 0)
			display_content(i, file, ac, av);
		already_printed(error);
		close(file);
		i++;
	}
	return (0);
}
