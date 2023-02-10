/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:07:24 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 12:17:34 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
char f(unsigned int i, char c)
{
 	printf("La fonction f - i = %d and char = %c\n", i, c);
 	return  - 32;
}


int main()
{
 	char str[20] = "test salome";
 	printf("Le string est %s\n", str);
 	ft_strmapi(str, f);
 	return 0;
}
*/
