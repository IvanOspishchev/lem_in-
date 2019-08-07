/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_shortest_path_.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:20 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:06:01 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void	dijkstra_indexing(t_queue *queue, t_lem *lem)
{
	t_room *cur_room;
	t_room *tmp;
//	t_room *room_arr;

	add_to_queue(lem->begin, queue);
	lem->begin->visited = 1;
	while (queue->size > 0)
	{
		cur_room = pop_from_queue(queue);
		tmp = cur_room->next;
		while (tmp)
		{
			if (tmp->visited == 0 && tmp->self->visited == 0)
			{
				add_to_priority_queue(tmp->self, queue);
				tmp->self->visited = 1;
			}
			if (tmp->visited == 0 && (cur_room->dijkstra + 1 < tmp->self->dijkstra))
				tmp->self->dijkstra = cur_room->dijkstra + 1;
			tmp = tmp->next;
		}
	}
}

static void	dijkstra_reset(t_lem *lem)
{
	t_room **roomarr;

	roomarr = lem->adj;

	while (*roomarr)
	{
		(*roomarr)->dijkstra = INT_MAX;
		(*roomarr)->visited = 0;
		roomarr++;
	}
}

int check_link(t_room *src, t_room *dest)
{
	src = src->next;
	while (src->next && src->self != dest)
		src = src->next;
	return (src->visited == 1) ? 0 : 1;
}

static t_path	*dijkstra_backtrace(t_lem *lem)
{
	t_room *end;
	t_path *spath;
	t_room *cur_room;
	t_room *tmp;

	end = lem->end;
	if (end->dijkstra == INT_MAX)
		return (NULL);
	spath = create_path();
	add_to_path(spath, end);
	cur_room = end;
	while (cur_room != lem->begin)
	{
		tmp = cur_room->next;
		while (tmp)
		{
			if (tmp->self->dijkstra <= cur_room->dijkstra && check_link(tmp->self, cur_room))
				cur_room = tmp->self;
			tmp = tmp->next;
		}
		add_to_path(spath, cur_room);
	}
	return (spath);
}

t_path	*reverse_path(t_path *path)
{
	t_path *reversed;
	t_room *tmp;

	if (!path)
		return (NULL);
	reversed = create_path();
	tmp = path->end;
	while (tmp)
	{
		add_to_path(reversed, tmp);
		tmp = tmp->prev;
	}
	return (reversed);
}

t_path	*dijkstra_search(t_lem *lem)
{
	t_path *shortest_path;

	dijkstra_reset(lem);
	lem->begin->dijkstra = 0;
	t_queue	*queue = ft_memalloc(sizeof(t_queue));

	dijkstra_indexing(queue, lem);
	shortest_path = dijkstra_backtrace(lem);

	return (reverse_path(shortest_path));
}