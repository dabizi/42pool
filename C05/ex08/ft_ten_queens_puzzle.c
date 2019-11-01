/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@82.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:81:18 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/13 19:33:29 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_diagonal_possible(char board[][10], int row, int col)
{
	int i;
	int j;

	j = col;
	i = row;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 'Q')
			return (0);
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i >= 0 && j < 10)
	{
		if (board[i][j] == 'Q')
			return (0);
		j++;
		i--;
	}
	return (1);
}

int		ft_is_queen_possible(char board[][10], int row, int col)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (board[i][col] == 'Q')
			return (0);
		i++;
	}
	if (!(ft_is_diagonal_possible(board, row, col)))
		return (0);
	return (1);
}

void	display(char board[][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			if (board[i][j] == 'Q')
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	write(1, "\n", 1);
}

void	solve_aueen(char board[][10], int row, int *ptr)
{
	int i;

	i = 0;
	if (row == 10)
	{
		display(board);
		*ptr += 1;
	}
	while (i < 10)
	{
		if (ft_is_queen_possible(board, row, i))
		{
			board[row][i] = 'Q';
			solve_aueen(board, row + 1, ptr);
			board[row][i] = '0';
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		i;
	int		j;
	int		result;
	int		*ptr;
	char	board[10][10];

	i = 0;
	result = 0;
	ptr = &result;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = '0';
			j++;
		}
		i++;
	}
	solve_aueen(board, 0, ptr);
	return (result);
}

int		main(void)
{
	ft_ten_queens_puzzle();
}
