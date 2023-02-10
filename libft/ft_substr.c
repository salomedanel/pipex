/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:37:55 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/18 16:43:11 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count_size(size_t size, size_t len, int start, char const *s)
{
	if (start > ft_strlen(s))
	{
		size = 0;
		return (size);
	}
	if (len >= (unsigned int) ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	char			*new_str;
	unsigned int	i;

	if (s == NULL)
		return (0);
	size = 0;
	size = ft_count_size(size, len, start, s);
	i = 0;
	new_str = malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (0);
	while (i < size)
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char *s;
	unsigned int start;
	size_t len;

	s = "0123456789";
	start = 9;
	len = 10;
	s = ft_substr(s, start, len);
	printf("%s\n", s);
	free(s);
}
*/
