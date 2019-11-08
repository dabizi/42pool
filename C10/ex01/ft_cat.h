/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:53:44 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 11:07:23 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <libgen.h>

# define BUFFER_SIZE 4096

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_display(char *av0, char *arg);
void	ft_cat(void);
int		ft_error(char *av0, char *arg);

#endif
