/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:03:08 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/06 10:23:27 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_word(char *str, int i, int capitalize)
{
	if (capitalize)
		return (1);
	if (str[i] < '0' || str[i] > 'z')
		return (1);
	if (str[i] > 'Z' && str[i] < 'a')
		return (1);
	if (str[i] > '9' && str[i] < 'A')
		return (1);
	return (0);
}

int		ft_short(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] -= 32;
		return (0);
	}
	else if (str[i] >= '0' && str[i] <= '9')
		return (0);
	else if (str[i] >= 'A' && str[i] <= 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int capitalize;
	int i;

	capitalize = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (capitalize)
		{
			capitalize = ft_short(str, i);
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		capitalize = ft_is_word(str, i, capitalize);
		i++;
	}
	return (str);
}
