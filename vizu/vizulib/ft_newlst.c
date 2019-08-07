/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:43 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:58 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

t_lem			*ft_newlem(void)
{
	t_lem		*new;

	new = (t_lem *)malloc(sizeof(t_lem));
	if (new)
	{
		new->s = NULL;
		new->ants = 0;
		new->rooms_cnt = 0;
		new->begin = NULL;
		new->end = NULL;
		new->adj = NULL;
		new->oper = 0;
		new->path_count = INT_MAX;
		new->nb = 1;
		new->n = 0;
	}
	return (new);
}

t_room			*ft_newroom(void)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new)
	{
		new->ant = 0;
		new->x = 0;
		new->y = 0;
		new->name = NULL;
		new->link_count = 0;
		new->next = NULL;
		new->self = NULL;
		new->prev = NULL;
		new->visited = 0;
		new->color = 16777215;
		new->dijkstra = INT_MAX;
		new->queue_next = NULL;
	}
	return (new);
}

t_split			*ft_newsplit(void)
{
	t_split		*new;

	new = (t_split *)malloc(sizeof(t_split));
	if (new)
	{
		new->l = 0;
		new->name1 = NULL;
		new->name2 = NULL;
		new->name3 = NULL;
		new->begin = 0;
		new->end = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
