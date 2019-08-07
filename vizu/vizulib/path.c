/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:47 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:28 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void	fill_intersection_array(t_path *path, t_lem *lem)
{
	char *array;
	int i;
	t_room *start;

	start = path->start;
	array = ft_memalloc(sizeof(char) * (lem->rooms_cnt + 1));
	i = 0;
	while (start)
	{
		array[start->nb] == 0 ? (array[start->nb])++ : throw_error("path error");
		i++;
		start = start->next;
	}
	if (i != path->len)
		throw_error("fill intersection arr error");
	path->intersection_arr = array;
}

t_path	*create_path()
{
	t_path	*path;

	path = malloc(sizeof(t_path));
	path->end = NULL;
	path->start = NULL;
	path->len = 0;
	path->next = NULL;
	path->intersection_arr = NULL;
	return (path);
}

void	print_path(t_path *path)
{
	t_room *start;

	if (!path)
	{
		printf("empty path\n");
		return ;
	}
	start = path->start;
	while (start)
	{
		printf("%s->", start->name);
		start = start->next;
	}
	printf("\n");
}

void	print_all_pathes(t_path **patharr)
{
	while (*patharr)
	{
		print_path(*patharr++);
	}
}