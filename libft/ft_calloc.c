/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:06:52 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 14:38:08 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	size_t nmemb;
	char *str;
	size_t i;

	nmemb = 5;
	i = 0;
	str = NULL;
	while (i < nmemb)
	{
		printf("bef funct: str[%ld] = %d\n", i, str[i]);
		i++;
	}
	printf("\n");
	i = 0;
	str = calloc(nmemb, sizeof(char));
	while (i < nmemb)
	{
		printf("my calloc: str[%ld] = %d\n", i, str[i]);
		i++;
	}
	printf("\n");
	i = 0;
	str = ft_calloc(nmemb, sizeof(char));
	while (i < nmemb)
	{
		printf("library: str[%ld] = %d\n", i, str[i]);
		i++;
	}
}
*/
