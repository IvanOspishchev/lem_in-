/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:02:25 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:41 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int 	is_intersect(t_path *path1, t_path *path2)
{
	t_path *shorter;
	t_path *longer;
	t_room *shorthead;

	shorter = (path1->len < path2->len) ? path1 : path2;
	longer = (shorter == path1) ? path2 : path1;
	shorthead = shorter->start;
	while (shorthead)
	{
		if (shorthead != shorter->start && shorthead != shorter->end)
			if(longer->intersection_arr[shorthead->nb] != 0)
				return (1);
		shorthead = shorthead->next;
	}
	return (0);
}

int		is_intersecting_n_paths(t_path **path_arr, int size)//todo testing
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (is_intersect(path_arr[i], path_arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_group	*delete_intersecting_paths(t_group *group)
{
	int i;
	int j;
	t_path **patharr;
	int newsize;
	t_path **newpatarr;

	newsize = group->size;
	patharr = group->path_array;

	i = 0;
	while (i < group->size)
	{
		j = i + 1;
		while (j < group->size)
		{
			if (patharr[i] && patharr[j])
				if (is_intersect(patharr[i], patharr[j]))
				{
					if (patharr[i]->len > patharr[j]->len)
						patharr[i] = NULL;
					else
						patharr[j] = NULL;
					newsize--;
				}
			j++;
		}
		i++;
	}

	i = 0;
	j = 0;
	newpatarr = malloc(sizeof(t_path*) * newsize);
	while (i < group->size)
	{
		if (patharr[i])
			newpatarr[j++] = patharr[i];
		i++;
	}
	//todo free old group
	return create_group(newpatarr, newsize);
}