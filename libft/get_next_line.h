/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:32:47 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/18 16:53:55 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//int		ft_strlen(char *str);
//char	*ft_strchr(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		findnl(char *stash);
char	*ft_read(int fd, char *stash);
char	*clean_stash(char *stash, int index);
char	*ft_get_line(char *stash, char *line);
char	*get_next_line(int fd, int boolean);

#endif
