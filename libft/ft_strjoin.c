/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:25:24 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 15:16:05 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	j = 0;
	if (new_str == NULL)
		return (0);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char *s1;
	char *s2;
	
	s1 = "hello";
	s2 = "world";
	printf("%s\n", ft_strjoin(s1, s2));
}
*/
