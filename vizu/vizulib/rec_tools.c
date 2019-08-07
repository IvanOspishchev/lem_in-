/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:01 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:26 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int				ret_null(t_split *tmp)
{
	split_free(tmp);
	return (0);
}

int				common_room(t_split *tmp, char **s, const int *t)
{
	if (ft_len2(s) != 3)
	{
		split_free(tmp);
		ft_arraydel(s);
		return (0);
	}
	tmp->name1 = s[0];
	tmp->name2 = s[1];
	tmp->name3 = s[2];
	if (tmp->name1[0] == 'L' || !s[2] || !s[1]
				|| !check_number(s[2]) || !check_number(s[1]))
	{
		split_free(tmp);
		free(s);
		return (0);
	}
	if (*t == 1)
		tmp->begin = 1;
	else if (*t == 2)
		tmp->end = 1;
	free(s);
	return (1);
}

t_split			*addlst(t_split *tmp, int l, int *t)
{
	t_split		*split;

	split = ft_newsplit();
	tmp->next = split;
	split->prev = tmp;
	tmp->l = l;
	if (*t == 1)
		split->begin = 1;
	else if (*t == 2)
		split->end = 1;
	*t = 0;
	return (split);
}

int				linker(t_split *tmp, char **s)
{
	if (ft_len2(s) != 2)
	{
		split_free(tmp);
		ft_arraydel(s);
		return (0);
	}
	tmp->name1 = s[0];
	tmp->name2 = s[1];
	free(s);
	return (1);
}

int				dublicates(t_split *split)
{
	t_split		*tmp;

	while (split->prev)
		split = split->prev;
	while (split->next && split->l == 3)
	{
		tmp = split;
		split = split->next;
		if (ft_strequ(tmp->name1, split->name1))
			return (1);
	}
	return (0);
}
