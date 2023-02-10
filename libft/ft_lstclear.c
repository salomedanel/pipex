/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:12 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/21 17:47:45 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextelem;

	if (!lst || !del || !(*lst))
		return ;
	while (lst && *lst)
	{
		nextelem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextelem;
	}
}
