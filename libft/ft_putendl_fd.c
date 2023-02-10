/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:00:20 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 15:37:37 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd == 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	int fd = open("test_putendl.txt", O_CREAT | O_RDWR);
	ft_putendl_fd("salut cava ?", fd);
	return (0);
}
*/
