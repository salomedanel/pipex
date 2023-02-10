/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:49:44 by sdanel            #+#    #+#             */
/*   Updated: 2022/11/22 14:49:35 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nextelem;

	if (!lst || !f)
		return ;
	while (lst)
	{
		nextelem = lst->next;
		(*f)(lst->content);
		lst = nextelem;
	}
}
