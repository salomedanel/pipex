/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:22:39 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/16 10:26:30 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == -2147483648)
		return (11);
	else if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_write_nbr(int n, int size, int i, char *str)
{
	while (size > i)
	{
		str[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		i;

	size = ft_itoa_size(n);
	i = 0;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
		i = 1;
	}
	ft_write_nbr(n, size, i, str);
	str[size] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	n;
	n =-2147483648;
	printf("%d\n", ft_itoa_size(n));
	printf("%s\n", ft_itoa(n));
}
*/
