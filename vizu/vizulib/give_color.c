/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:02:10 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:45 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static t_path	*backtrace_path(t_room *room, t_lem *lem)
{
	t_path		*res_path;
	t_room		*cur_room;
	t_room		*link;
	t_room		*better_link;

	res_path = create_path();
	add_to_path(res_path, lem->end);
	cur_room = room->self;
	while (cur_room != lem->begin)
	{
		add_to_path(res_path, cur_room);
		link = cur_room->next;
		better_link = NULL;
		while (link)
		{
			if (!check_link(link->self, cur_room))
				if (!better_link || (link->self->dijkstra < better_link->self->dijkstra))
					better_link = link;
			link = link->next;
		}
		cur_room = better_link->self;
	}
	add_to_path(res_path, lem->begin);
	return (reverse_path(res_path));
}

static t_group	*make_group(t_lem *lem)
{
	t_path		**patharr;
	t_room		*end;
	t_room		*link;
	int			i;

	i = 0;
	end = lem->end;
	link = end->next;
	patharr = ft_memalloc(sizeof(t_room*) * lem->end->link_count);
	while (link)
	{
		if (!check_link(link->self, end))
		{
			patharr[i] = backtrace_path(link, lem);
			fill_intersection_array(patharr[i++], lem);
		}
		link = link->next;
	}
	return (create_group(patharr, i));
}

t_group			*find_best_group(t_group *best_group, t_lem *lem)
{
	t_group		*cur_group;

	cur_group = make_group(lem);

	is_intersecting_n_paths(cur_group->path_array, cur_group->size);
	cur_group = delete_intersecting_paths(cur_group);
	if (!best_group)
		return (cur_group);
	if (cur_group && run_ants(cur_group, lem, 0) < run_ants(best_group, lem, 0))
		return (cur_group);
	return (best_group);
}

void			resert_color(t_mlx *mlx)
{
	t_room		**adj;
	int			i;

	adj = mlx->lem->adj;
	i = 0;
	while (adj[i])
	{
		adj[i]->color = mlx->white;
		i++;
	}
	mappaint(mlx);
	putman(mlx);
}

void			give_color(t_mlx *mlx)
{
	t_path		*shortest_path;
    t_group		*best_group;
	int			i;
	t_room		*path;

	i = 0;
    mlx->lem->max_group_size = calc_max_group_size(mlx->lem);
    best_group = NULL;
    while ((shortest_path = dijkstra_search(mlx->lem)) != NULL)
	{
		switch_links(shortest_path, mlx->lem);
		best_group = find_best_group(best_group, mlx->lem);
	}
	while (i < best_group->size)
	{
		path = best_group->path_array[i]->start;
		while (path)
		{
			mlx->lem->adj[path->nb]->color = mlx->green;
			path = path->next;
		}
		i++;
	}
	mappaint(mlx);
	putman(mlx);
}
