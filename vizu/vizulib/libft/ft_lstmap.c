/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:16:58 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 16:03:29 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*root;

	while (lst && f)
	{
		if (!(new = f(lst)))
			return (NULL);
		root = new;
		while (lst->next)
		{
			lst = lst->next;
			if (!(new->next = f(lst)))
			{
				ft_lstdel(&root, &ft_dellst);
				return (NULL);
			}
			new = new->next;
		}
		lst = lst->next;
	}
	return (root);
}
