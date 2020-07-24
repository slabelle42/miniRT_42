/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:49:17 by slabelle          #+#    #+#             */
/*   Updated: 2019/11/11 18:40:19 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst && del)
	{
		tmp1 = *lst;
		while (tmp1)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			del(tmp2->content);
			free(tmp2);
		}
		*lst = NULL;
	}
}
