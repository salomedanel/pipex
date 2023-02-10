/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:19:40 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/13 15:13:20 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
/*
int	main(void)
{
	char s[] = "tripouille";
	printf("%s\n", strrchr(s, 't' + 256));
	printf("%s\n", ft_strrchr(s, 't' + 256));
	return (0);
}
*/
