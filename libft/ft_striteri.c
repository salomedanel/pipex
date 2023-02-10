/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:44:08 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/14 11:55:56 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
/*
void	f(unsigned int i, char *s)
{
	i = 0;
	printf("Fonction f - index[%d] = char %c\n", i, s[i]);
}

int	main(void)
{
	char str[20] = "test salome";
	printf("Le string est %s\n", str);
	ft_striteri(str, f);
	return (0);
}
*/
