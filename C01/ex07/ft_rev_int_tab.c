/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:09:13 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/04 10:30:09 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int to_inverse;
	int to_inverse2;

	to_inverse = 0;
	to_inverse2 = size - 1;
	while (to_inverse < (size / 2))
	{
		ft_swap(tab + to_inverse, tab + to_inverse2);
		to_inverse++;
		to_inverse2--;
	}
}
