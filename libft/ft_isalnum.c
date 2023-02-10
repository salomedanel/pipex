/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:18:32 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 12:08:33 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
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
	int a;

	a = 'H';
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", isalnum(a));
	return (0);
}
*/
