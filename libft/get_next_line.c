/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:05:13 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/18 16:40:10 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findnl(char *stash)
{
	int	i;

	i = 0;
	if (stash == NULL)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		read_res;
	int		i;

	read_res = 1;
	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	while (ft_findnl(stash) == 0 && read_res > 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(buf);
			return (0);
		}
		buf[i + read_res] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (stash == NULL)
			return (0);
	}
	free(buf);
	return (stash);
}

char	*ft_clean_stash(char *stash, int index)
{
	char	*new_stash;
	int		i;

	i = 0;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - index + 1));
	if (stash[0] == '\0')
	{
		free(new_stash);
		free(stash);
		return (0);
	}
	while (stash[index] != '\0')
	{
		new_stash[i] = stash[index];
		i++;
		index++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_get_line(char *stash, char *line)
{
	int	i;

	i = 0;
	if (stash[i] == '\0')
		return (0);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (0);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd, int boolean)
{
	static char	*stash[4096];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = NULL;
	if (boolean)
		return (free(stash[0]), free(line), NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	if (stash[fd] == NULL)
	{
		free(stash[fd]);
		return (0);
	}
	line = ft_get_line(stash[fd], line);
	i = ft_strlen(line);
	stash[fd] = ft_clean_stash(stash[fd], i);
	return (line);
}

/*
int	ma23,278,453 bytes in 5,570 blocksin(void)
{
	int 	fd = open("test.txt", O_RDONLY);
	int 	fd2 = open("test2.txt", O_RDONLY);
	char	*line;
	int		i;

	i = 1;
	while (i <= 15)
	{
		line = get_next_line(fd);
		printf("line #%d = %s", i, line);
		free(line);
	23,278,453 bytes in 5,570 blocks	line = get_next_line(fd2);
		printf("line #%d = %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/
