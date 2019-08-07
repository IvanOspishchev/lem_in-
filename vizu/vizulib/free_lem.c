/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:32 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:59 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void				free_adj(t_room **adj)
{
	t_room			*tmp;
	int				i;
	t_room			*prev;

	i = 0;
	while (adj[i])
	{
		tmp = adj[i]->next;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev);
		}
		free(adj[i]->name);
		free(adj[i]);
		i++;
	}
	free(adj);
}

void				free_lem(t_lem *lem)
{
	if (lem->adj)
		free_adj(lem->adj);
	free(lem);
}
