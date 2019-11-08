/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrandne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:14:53 by jgrandne          #+#    #+#             */
/*   Updated: 2019/07/24 14:30:49 by jgrandne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <libgen.h>

# define BUFFER_SIZE 4096

void	nofile_error(char *av0, char *arg);
void	permission_error(char *av0, char *arg);
void	directory_error(char **av);
int		already_printed(int error);
int		ft_error(char *av0, int ac, char *arg);
int		ft_atoi(char *str);
void	read_stdin(char **av);
int		ft_strlen(char *str);
void	ft_putstr_error(char *str);
void	display_title(int i, int ac, char **av);
int		filesz(int i, char **av);
void	display_content(int i, int file, int ac, char **av);

#endif
