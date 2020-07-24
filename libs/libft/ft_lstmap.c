/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:50:08 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/11 12:55:39 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (lst && f && del)
	{
		if (!(new = ft_lstnew(f(lst->content))))
			return (NULL);
		first = new;
		while (lst->next)
		{
			if (!(new->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (NULL);
			}
			lst = lst->next;
			new = new->next;
		}
		new->next = NULL;
		return (first);
	}
	return (NULL);
}
