/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:33:04 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 23:46:10 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void	display(char *flname)
{
	int		file;
	int		r;
	char	c;

	file = open(flname, O_RDONLY);
	if (file < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while ((r = read(file, &c, 1)))
		write(1, &c, 1);
	close(file);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(argv[1]);
	return (0);
}
