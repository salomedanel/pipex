/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:22 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 16:54:31 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 == *s2) && (*s1 != '\0'))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main(void)
{
	char *s1;
	char *s2;	

	s1 = "ç";
	s2 = "salut";
	printf("%d\n", strncmp(s1, s2, 10));
	printf("%d\n", ft_strncmp(s1, s2, 10));
}
*/
