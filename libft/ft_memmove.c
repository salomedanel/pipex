/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:33 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 15:09:37 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			*(char *)(dest + n - 1) = *(char *)(src + n - 1);
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/*
int	main (void) 
{
	char dest[] = "new string";
	const char src[]  = "old string";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 5);
	printf("After memmove dest = %s, src = %s\n", dest, src);
	return(0);
}
*/
