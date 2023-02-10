/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:39 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/18 10:50:10 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	char_c;
	size_t			i;

	char_s = (unsigned char *) s;
	char_c = (unsigned char) c;
	i = 0;
	if (s == NULL)
		return (0);
	while (i < n)
	{
		if (char_s[i] == char_c)
			return ((char *) s + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*s;
	int	c;
	size_t	n;
	char	*pos;
	size_t	i;

	s = "test salome";
	c = 's';
	n = 11;
	i = 0;
	pos = memchr(s, c, n);
	while (i < n)
	{
		printf("Pos[%ld] = %c\n", i, pos[i]);
		i++;
	}
	return (0);
}
*/
