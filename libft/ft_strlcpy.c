/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:14:03 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 12:16:53 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
	{
		j++;
	}
	if (size)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
/*
int	main(void)
{
	char *src;
	char dest[25];

	src = "bonjour";
	printf("%d\n", ft_strlcpy(dest, src, 7));
	return (0);
}
*/
