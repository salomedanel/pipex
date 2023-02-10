/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:11:39 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/21 13:15:14 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	is_charset(char const *str, char c, int i)
{
	if (c == '\0')
		return (0);
	if (str[i] == c)
		return (1);
	else
		return (0);
}

static int	ft_word_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (count);
		if (str[0] != c && i == 0)
		{
			count++;
			i++;
		}
		if (str[i] != c && str[i - 1] != c)
			i++;
		if (str[i] != c && str[i - 1] == c)
		{
			i++;
			count++;
		}
	}
	return (count);
}

static char	*ft_strndup(char const *str, int start, int end)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * ((end - start) + 1));
	if (tab == NULL)
		return (0);
	while (start < end)
	{
		tab[i] = str[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static int	ft_create_word(char const *str, char c, char **tab)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (i < ft_strlen(str))
	{
		while (is_charset(str, c, i) == 0 && str[i])
			i++;
		if (i > start)
		{
			tab[j] = ft_strndup(str, start, i);
			if (!tab[j])
				return (0);
			j++;
		}
		i++;
		start = i;
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!str)
		return (0);
	tab = malloc(sizeof(char *) * (ft_word_count(str, c) + 1));
	if (tab == NULL)
		return (0);
	if (!ft_create_word(str, c, tab))
	{
		while (tab[i] != 0)
		{
			free(tab[i]);
			i++;
		}
	}
	tab[ft_word_count(str, c)] = 0;
	return (tab);
}
/*
int	main(void)
{
	char **tab;
	char *str = " olol";
	char c = '-';
	int i = 0;
	printf("%d\n", ft_word_count(str, c));
	tab = ft_split(str, c);
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
