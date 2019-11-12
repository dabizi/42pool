/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:51:09 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/22 12:43:14 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOOLS_H
# define FT_TOOLS_H

typedef struct	s_operator
{
	char const	*oper;
	void		(*f)(int, int);
}				t_oper;

void			ft_add(int a, int b);
void			ft_sub(int a, int b);
void			ft_multiply(int a, int b);
void			ft_div(int a, int b);
void			ft_mod(int a, int b);

int				ft_atoi(char *str);
int				ft_is_whitespace(char a);
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
void			ft_putchar(char a);
int				ft_strcmp(char *str, char const *str2);

#endif
