/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:18 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		if_next_end(t_room *tmp, t_path *path, int ants_bg, t_lem *lem)
{
	(tmp == path->start && lem->n && ants_bg) ? tmp->ant += lem->nb : 0;
	(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->next->name) : 0;
	path->end->ant++;
	(tmp != path->start) ? tmp->ant = 0 : 0;
	if (tmp->prev && tmp->prev->ant != 0)
	{
		while (tmp->prev != path->start && tmp->prev->ant > 0)
		{
			tmp->ant = tmp->prev->ant;
			(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
			tmp = tmp->prev;
			tmp->ant = 0;
		}
		if (tmp->prev == path->start && ants_bg)
		{
			tmp->ant = lem->nb;
			(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
	}
}

static void		if_midd(t_room *tmp, t_path *path, int ants_bg, t_lem *lem)
{
	while (tmp && tmp->prev != path->start && tmp->ant != 0)
	{
		tmp->next->ant = tmp->ant;
		(lem->n) ? printf("L%d-%s ", tmp->next->ant, tmp->next->name) : 0;
		(!ants_bg && tmp->prev->ant == 0) ? tmp->ant = 0 : 0;
		tmp = tmp->prev;
	}
	if (tmp && tmp->prev == path->start && tmp->ant)
	{
		tmp->next->ant = tmp->ant;
		tmp->ant = 0;
		(lem->n) ? printf("L%d-%s ", tmp->next->ant, tmp->next->name) : 0;
		if (ants_bg)
		{
			tmp->ant = lem->nb;
			(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
		else
			tmp->ant = 0;
	}
}

static void		if_shit(t_room *tmp, int ants_bg, t_lem *lem)
{
	tmp->next->ant++;
	(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->next->name) : 0;
	if (ants_bg)
	{
		tmp->ant = lem->nb;
		(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
	}
	else
		tmp->ant = 0;
}

void			push_ants(t_path *path, int ants_bg, t_lem *lem)
{
	t_room		*tmp;

	tmp = path->end->prev;
	while (!tmp->ant && tmp->prev != path->start && tmp != path->start)
		tmp = tmp->prev;
	if (tmp->next == path->end && tmp->prev != path->start)
		if_next_end(tmp, path, ants_bg, lem);
	else if (tmp->prev == path->start && !tmp->ant)
	{
		if (ants_bg)
		{
			tmp->ant = lem->nb;
			(lem->n) ? printf("L%d-%s ", tmp->ant, tmp->name) : 0;
		}
	}
	else if (tmp->next == path->end && tmp->prev == path->start)
		if_shit(tmp, ants_bg, lem);
	else
		if_midd(tmp, path, ants_bg, lem);
}

int				run_ants(t_group *group, t_lem *lem, int n)
{
	int			i;

	lem->n = n;
	group->ants = lem->ants;
	make_prev_for_path(group, lem);
	while (lem->ants > is_ants_at_finish(group))
	{
		i = 0;
		while (i < group->size)
		{
			if (group->path_array[i])
			{
				push_ants(group->path_array[i++],
		(group->ants > 0) ? group->ants : 0, lem);
				group->ants--;
				lem->nb++;
			}
		}
		(lem->n) ? printf("\n") : 0;
		lem->oper++;
	}
	i = 0;
	while (i < group->size)
		group->path_array[i++]->end->ant = 0;
	return (lem->oper);
}
