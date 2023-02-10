/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:03:16 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/18 16:54:09 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (*(s2 + i))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
	{
		free(s2);
		return (0);
	}
	i = -1;
	j = 0;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
