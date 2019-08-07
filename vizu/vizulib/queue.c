/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:53 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void	add_to_queue(t_room *room, t_queue *queue)
{
	if (queue->size == 0)
	{
		queue->start = queue->end = room;
	}
	else
	{
		queue->end->queue_next = room;
		queue->end = room;
	}
	room->queue_next = NULL;
	queue->size++;
}

void	add_to_priority_queue(t_room *room, t_queue *queue)
{
	t_room *start;

	room->queue_next = NULL;
	queue->size++;
	start = queue->start;
	if (queue->size == 1)
	{
		queue->start = queue->end = room;
		return ;
	}
	if (room->dijkstra <= start->dijkstra)
	{
		room->queue_next = start;
		queue->start = room;
		return ;
	}
	while (start)
	{
		if (start->queue_next == NULL)
		{
			start->queue_next = room;
			queue->end = room;
			room->queue_next = NULL;//
			break ;
		}
		if (room->dijkstra <= start->queue_next->dijkstra)
		{
			if (start == queue->end)
				queue->end = room;
			room->queue_next = start->queue_next;
			start->queue_next = room;
			break ;
		}

		start = start->queue_next;
	}
}

t_room	*pop_from_queue(t_queue *queue)
{
	t_room *res;

	if (queue->size <= 0)
		return (NULL);
	else
	{
		if (queue->size == 1)
			queue->end = NULL;
		res = queue->start;
		queue->start = queue->start->queue_next;
	}
	queue->size--;
	return (res);
}
