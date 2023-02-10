/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:36:06 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 12:09:31 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}	
}
/*
int	main(void)
{
	int	a;

	a = '3';
	printf("%d\n", ft_isascii(a));
	printf("%d\n", isascii(a));
	return (0);
}
*/
