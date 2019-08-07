/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappaint_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:01 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:34 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void		release_visited(t_room **adj)
{
	int		i;
	t_room	*tmp;

	i = 0;
	while (adj[i])
	{
		tmp = adj[i]->next;
		while (tmp)
		{
			tmp->visited = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

void		visited(t_room *room, t_room *adj)
{
	room = room->next;
	while (room->self != adj)
		room = room->next;
	room->visited = 1;
}

void		cloner(t_room *cl, t_room *adj, t_mlx *mlx)
{
	*cl = *adj;
	cl->x = adj->x * mlx->l + mlx->x_add;
	cl->y = adj->y * mlx->l + mlx->y_add;
}

void		graph_color(t_lem *lem, t_room *adj, t_mlx *mlx, int *col)
{
	if (lem->begin == adj)
		*col = mlx->blue;
	else if (lem->end == adj)
		*col = mlx->yellow;
	else if (adj->color == mlx->green)
		*col = mlx->green;
	else
		*col = mlx->white;
}
