/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:05:01 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:20 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void			switch_them(int nb, int nb1, t_room **adj)
{
	t_room			*room;

	room = adj[nb]->next;
	while (room->self != adj[nb1] && room->next)
		room = room->next;
	if (room && room->visited == 0)
		room->visited = 1;
	else if (room && room->visited == 1)
	{
		room->visited = 0;
		room = adj[nb1]->next;
		while (room->self != adj[nb] && room->next)
			room = room->next;
		room->visited = 1;
	}
}

void				switch_links(t_path *path, t_lem *lem)
{
	t_room			*room;
	t_room			*tmp;
	t_room			**adj;

	if (!path)
		return ;
	adj = lem->adj;
	room = path->start;
	while (room->next)
	{
		tmp = room->next;
		switch_them(room->nb, tmp->nb, adj);
		room = room->next;
	}
}
