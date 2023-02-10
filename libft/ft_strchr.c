/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:58:25 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 17:43:01 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (0);
}
/*
int	main(void)
{
	char *s = "\0";
	printf("%p\n", ft_strchr(s, '\0'));
	printf("%p\n", strchr(s, '\0'));
	return (0);
}
*/
