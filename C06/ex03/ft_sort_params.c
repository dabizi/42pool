/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:12:22 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/10 08:33:45 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i] - s2[i]);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (s1[i] - s2[i]);
	else
		return (0);
}

void	swap(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		is_sorted;

	is_sorted = 1;
	while (is_sorted)
	{
		i = 0;
		is_sorted = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				is_sorted = 1;
			}
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	swap(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
