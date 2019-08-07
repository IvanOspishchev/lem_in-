/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:55 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:21 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void			split_free(t_split *split)
{
	t_split		*tmp;

	if (!split)
		return ;
	while (split->prev)
		split = split->prev;
	while (split)
	{
		tmp = split;
		split = split->next;
		if (tmp->name1)
		{
			free(tmp->name1);
			tmp->name1 = NULL;
			if (tmp->name2)
			{
				free(tmp->name2);
				tmp->name2 = NULL;
				(tmp->l == 3) ? free(tmp->name3) : 0;
				tmp->name3 = NULL;
			}
		}
	}
}
