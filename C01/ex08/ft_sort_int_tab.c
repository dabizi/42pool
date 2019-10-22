/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:30:37 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/04 10:55:41 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int is_ordered;

	i = 0;
	is_ordered = 1;
	while (is_ordered)
	{
		is_ordered = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(tab + i, tab + (i + 1));
				is_ordered = 1;
			}
			i++;
		}
		i = 0;
	}
}
