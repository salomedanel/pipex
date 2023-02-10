/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:45:40 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/22 14:49:13 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nextelem;
	t_list	*new;

	new = NULL;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		nextelem = ft_lstnew((*f)(lst->content));
		if (!nextelem)
		{
			ft_lstclear(&lst, del);
			free(new);
			return (0);
		}
		ft_lstadd_back(&new, nextelem);
		lst = lst->next;
	}
	return (new);
}
