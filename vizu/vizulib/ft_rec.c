/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:58 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:55 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "vizulib.h"

static int		common_cond(t_split **tmp, int *t, t_lem *lem, char *s)
{
	if (ft_count_char(s, ' ') == 3)
	{
		*tmp = (*tmp) ? addlst(*tmp, 3, t) : ft_newsplit();
		if (!common_room(*tmp, ft_strsplit(s, ' '), t))
		{
			free(s);
			free(*tmp);
			*tmp = NULL;
			return (0);
		}
		lem->rooms_cnt++;
		*t = 0;
	}
	else if (ft_count_char(s, '-') == 2)
	{
		*tmp = (*tmp) ? addlst(*tmp, 2, t) : ft_newsplit();
		linker(*tmp, ft_strsplit(s, '-'));
	}
	return (1);
}

static int		body_of_getting(char *s, t_split **tmp, int *t, t_lem *lem)
{
	if (s[0] != '#' && !cnt_char(s, 32)
		&& !cnt_char(s, '-') && ft_isdigit(s[0]))
	{
		if (!lem->ants && check_number(s))
			lem->ants = ft_atoi(s);
		else
			return (ret_null(*tmp));
	}
	else if (ft_strequ(s, "##start") || ft_strequ(s, "##end"))
		*t = (s[2] == 's') ? 1 : 2;
	else if (s[0] != '#')
		if (!common_cond(tmp, t, lem, s))
			return (0);
	if (s[0] == '\0')
		return (ret_null(*tmp));
	free(s);
	return (1);
}

static t_split	*getting(int fd, t_lem *lem)
{
	int			t;
	char		*s;
	t_split		*tmp;

	tmp = NULL;
	while (get_next_line(fd, &s))
	{
		if (!(body_of_getting(s, &tmp, &t, lem)))
			return (NULL);
	}
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_split			*ft_rec(char *file_name, t_lem *lem)
{
	int			fd;
	t_split		*tmp;

	if (!(fd = open(file_name, O_RDONLY)) || fd < 0)
		return (NULL);
	if (!(tmp = getting(fd, lem)))
		return (NULL);
	if (!lem->rooms_cnt || lem->ants <= 0 || dublicates(tmp))
	{
		split_free(tmp);
		return (NULL);
	}
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
