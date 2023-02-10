/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:20:44 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 15:28:29 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_count_set(int i, const char *s1, const char *set)
{
	while (is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	char			*new_s1;
	unsigned int	s1_len;

	if (s1 == NULL || set == NULL)
		return (0);
	s1_len = ft_strlen(s1);
	start = 0;
	start = ft_count_set(start, s1, set);
	if (start == s1_len)
	{
		new_s1 = malloc(sizeof(char) * 1);
		if (new_s1 == NULL)
			return (0);
		new_s1[0] = '\0';
		return (new_s1);
	}
	while (is_in_set(s1[s1_len - 1], set) == 1)
		s1_len--;
	s1_len = s1_len - start;
	new_s1 = ft_substr(s1, start, s1_len);
	return (new_s1);
}
/*
int	main(void)
{
	char *s1 = "sbonjouuuurrro";
	char *set = "so";
	char *res;
	res = ft_strtrim(s1, set);
	printf("%s\n", res);
	return (0);
}
*/
