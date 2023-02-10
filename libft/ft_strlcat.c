/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:16 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 10:55:58 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	if (dest == 0)
		return (0);
	while (src[src_len] != '\0')
		src_len++;
	while (dest[dest_len] != '\0')
		dest_len++;
	if (!size)
		return (src_len);
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dest_len > size)
		return (src_len + size);
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char	src[] = "nyan !";
	char	dest[] = "Hel";
	printf("%d\n", ft_strlcat(((void*)0), src, 0));
	return (0);
}
*/
