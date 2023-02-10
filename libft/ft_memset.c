/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:44:53 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/18 10:58:31 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*char_s;

	i = 0;
	char_s = (char *) s;
	while (i < n)
	{
		char_s[i] = c;
		i++;
	}
	return (s);
}
/*
int main () 
{
	char str[10];
	int i;
	int a;
	
	i = 0;
	a = 'A';
	ft_memset(str, a, 10);
	while (i < 10)
	{
		printf("%c\n", str[i]);
		i++;
	}
   	return(0);
}
*/
