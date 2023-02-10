/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:35:46 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/22 13:46:55 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{	
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "hello";
	char dest[10];
	ft_memcpy(dest, src, strlen(src));
	printf("src: %s\n", src);
        printf("dest: %s\n", dest);
	memcpy(dest, src, strlen(src));
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	return (0);
}
*/
