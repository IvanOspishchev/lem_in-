/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_pathfinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:10 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:25 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"


void	add_to_path(t_path *path, t_room *room)
{
	t_room *newroom = ft_newroom();
	*newroom = *room;

	newroom->prev = path->end;
	path->len++;
	if (!path->start)
		path->start = newroom;
	if (path->end)
		path->end->next = newroom;
	path->end = newroom;
	newroom->next = NULL;
}

void	remove_last_from_path(t_path *path)
{
	t_room *end;

	end = path->end;
	path->len--;
	if (path->len > 0)
	{
		path->end = end->prev;
		end->prev->next = NULL;
	}
	free(end);
}



//typedef struct {
//	int path_count;
//	t_path *path_list;
//} t_allpathes;

t_path	*copy_path(t_path *path)
{
	t_path *copy;
	t_room *pathhead;

	pathhead = path->start;
	copy = create_path();
	while (pathhead)
	{
		add_to_path(copy, pathhead);
		pathhead = pathhead->next;
	}
	return (copy);
}

void 	add_path_to_all(t_path *path, t_path **path_list)
{
//	t_path *tmp;
	path = copy_path(path);
	if (*path_list == NULL)
		*path_list = path;
	else{
//		tmp = *path_list;
		path->next = *path_list;
		*path_list = path;
	}
}
int recursdepth = 0;

int 	rpf(t_room *room, t_lem *lem, t_path *path, t_path **pathlist)
{	//printf("rec depth-%d\n", recursdepth);
//	print_path(path);
//	printf("%d\n", room->nb);
	int path_count = 0;
	recursdepth++;
	t_room *this_room = room;

//	if (room->link_count)
	add_to_path(path, room);
	if (room == lem->end)
	{
		recursdepth--;
		add_path_to_all(path, pathlist);
		remove_last_from_path(path);
		return (1);
	}
	room->visited = 1;
	room = room->next;
	while (room)
	{
		if (room->self->visited == 0)
		{
			path_count += rpf(lem->adj[room->nb], lem, path, pathlist);
		}
		room = room->next;
	}
	this_room->visited = 0;
	remove_last_from_path(path);
	recursdepth--;
	return (path_count);
}