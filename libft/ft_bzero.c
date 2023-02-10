/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:09:39 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/18 10:45:25 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*char_s;

	i = 0;
	char_s = (char *) s;
	while (i < n)
	{
		char_s[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char str[10];
	int n;
	int i;

	n = 10;
	i = 0;
	ft_bzero(str, n);
	while (i < n)
	{
		printf("%c\n", str[i]);
		i++;
	}
	return (0);
}
*/
