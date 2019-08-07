/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappaint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:15 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:33 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		print_graph(t_room *tmp, t_mlx *mlx, t_room *adj)
{
	t_room		*room;
	t_room		*clone1;
	t_room		*clone2;

	clone1 = ft_newroom();
	clone2 = ft_newroom();
	while (tmp && tmp->self)
	{
		if (!tmp->visited)
		{
			tmp->visited = 1;
			room = tmp->self;
			cloner(clone1, adj, mlx);
			cloner(clone2, room, mlx);
			ft_bresenham(clone1, clone2, mlx);
			visited(room, adj);
		}
		tmp = tmp->next;
	}
	free(clone1);
	free(clone2);
}

void			mappaint(t_mlx *mlx)
{
	int			i;
	int			col;
	t_room		**adj;
	t_lem		*lem;

	lem = mlx->lem;
	adj = lem->adj;
	i = 0;
	while (adj[i])
	{
		print_graph(adj[i]->next, mlx, adj[i]);
		graph_color(lem, adj[i], mlx, &col);
		if (mlx->fill % 2 != 0)
			circle((adj[i]->x * mlx->l) + mlx->x_add,
				(adj[i]->y * mlx->l) + mlx->y_add, mlx, col);
		else
			fcircle((adj[i]->x * mlx->l) + mlx->x_add,
				(adj[i]->y * mlx->l) + mlx->y_add, mlx, col);
		i++;
	}
	release_visited(adj);
}
