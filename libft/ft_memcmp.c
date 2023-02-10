/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:56 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/17 11:03:45 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;
	size_t			i;

	char_s1 = (unsigned char *) s1;
	char_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (char_s1[i] == char_s2[i])
			i++;
		else
			return (char_s1[i] - char_s2[i]);
	}
	return (0);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	int	n;

	s1 = "sylome";
	s2 = "sy";
	n = 10;
	printf("%d\n", memcmp(s1, s2, n));
	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);
}
*/
