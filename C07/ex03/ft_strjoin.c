/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:48:07 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/18 17:54:39 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*strjoin;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	if (size > 1)
		len += (size - 1) * ft_strlen(sep);
	if (!(strjoin = (char *)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	if (size <= 0)
		return (strjoin);
	i = 0;
	strjoin[0] = '\0';
	while (i < size)
	{
		strjoin = ft_strcat(strjoin, strs[i]);
		if (i < size - 1)
			strjoin = ft_strcat(strjoin, sep);
		i++;
	}
	return (strjoin);
}
