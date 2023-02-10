/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:20:47 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/21 13:55:59 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (0);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*
int	main(void)
{
	t_list *test = ft_lstnew("hello");
	puts(test->content);
	return (0);
}
*/
