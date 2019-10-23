/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 08:41:29 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/07 18:27:58 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_base(unsigned int nb, unsigned int is_adress)
{
	char			*base;
	unsigned int	copy;
	unsigned int	length;

	length = 1;
	copy = nb;
	base = "0123456789abcdef";
	if (is_adress)
	{
		while (copy > 16)
		{
			copy /= 16;
			length++;
		}
		length = 15 - length;
		while (length > 0)
		{
			write(1, "0", 1);
			length--;
		}
	}
	if (nb >= 16)
		ft_base((nb / 16), 0);
	write(1, &(base[nb % 16]), 1);
}

void	ft_putcharhex(char *str, int is_last_line, int reste)
{
	int i;
	int empty;
	int is_passed;

	i = 0;
	empty = 16 - reste;
	is_passed = 0;
	while (i < 16)
	{
		if (is_last_line && i == reste)
			is_passed = 1;
		if (is_passed)
			write(1, "  ", 2);
		else if ((char)str[i] < 16)
			write(1, "0", 1);
		if (!is_passed)
			ft_base((char)str[i], 0);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_putstr(char *str, int is_last_line, int reste)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (is_last_line && i == reste)
			break ;
		else if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	display(void *addr, int size, int i, int is_last_line)
{
	ft_base((int)addr + i, 1);
	write(1, ": ", 2);
	ft_putcharhex(addr + i, is_last_line, size % 16);
	ft_putstr(addr + i, is_last_line, size % 16);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int count;
	unsigned int i;
	unsigned int is_last_line;
	unsigned int is_sixteen;

	if (!size)
		return (addr);
	count = 0;
	i = 0;
	is_last_line = 0;
	is_sixteen = 1;
	if (size % 16 == 0)
		is_sixteen = 0;
	while (count < (size / 16 + is_sixteen))
	{
		if (count == (size / 16))
			is_last_line = 1;
		display(addr, size, i, is_last_line);
		count++;
		i += 16;
	}
	return (addr);
}
