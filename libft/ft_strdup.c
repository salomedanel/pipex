/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:20:04 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 15:30:13 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int			i;
	char		*s_dup;
	const char	*char_s;

	i = 0;
	char_s = (char *) s;
	s_dup = malloc(sizeof(char) * ft_strlen(char_s) + 1);
	if (s_dup == NULL)
		return (0);
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
/*
int	main(void)
{
	char	*s;
	
	s = "hello cava";
	printf("%s\n", strdup(s));
	printf("%s\n", ft_strdup(s));
}
*/
