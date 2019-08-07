/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:02:43 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:36 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static int			ind_sch(t_lem *lem, char *s)
{
	int				i;
	t_room			**adj;

	adj = lem->adj;
	i = 0;
	while (adj[i] && ft_strcmp(adj[i]->name, s) != 0)
		i++;
	return (i);
}

static void			lnk_connect(t_room **adj, int n1, int n2)
{
	t_room			*room;
	t_room			*tmp;

	room = ft_newroom();
	if (!adj[n1]->next)
		adj[n1]->next = room;
	else
	{
		tmp = adj[n1];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
		room->prev = tmp;
	}
	adj[n1]->link_count += 1;
	room->self = adj[n2];
	room->nb = n2;
}

static int			double_linked(int n1, int n2, t_room **adj)
{
	t_room			*tmp;

	tmp = adj[n1]->next;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->self == adj[n2])
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int					link_make(t_lem *lem, t_split *tmp)
{
	int				n1;
	int				n2;

	if (!lem->begin || !lem->end || !tmp)
		return (0);
	if (tmp->l != 2)
		return (2);
	while (tmp != NULL)
	{
		n1 = ind_sch(lem, tmp->name1);
		n2 = ind_sch(lem, tmp->name2);
		if (!lem->adj[n1] || !lem->adj[n2])
			return (0);
		if (!double_linked(n1, n2, lem->adj)
			&& !double_linked(n2, n1, lem->adj))
		{
			lnk_connect(lem->adj, n1, n2);
			lnk_connect(lem->adj, n2, n1);
		}
		tmp = tmp->next;
	}
	return (1);
}
