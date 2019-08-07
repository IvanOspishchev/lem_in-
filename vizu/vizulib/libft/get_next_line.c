/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:10:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/08 14:05:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_memadd(char **tmp, const int fd, UL mem)
{
	char		*del;

	del = tmp[fd];
	if (!(tmp[fd] = ft_strnew(mem)))
		return (0);
	if (del)
	{
		ft_memcpy(tmp[fd] + 8, del + 8, *(((UL *)del) + 3) - 8);
		free(del);
	}
	else
	{
		*((((UL **)tmp)[fd]) + 1) = 33;
		*((((UL **)tmp)[fd]) + 2) = 33;
		*((((UL **)tmp)[fd]) + 3) = 33;
	}
	*(((UL **)tmp)[fd]) = mem;
	return (1);
}

static int		detect(char *tmp)
{
	while (*(((UL *)tmp) + 2) != *(((UL *)tmp) + 3))
	{
		if (tmp[*(((UL *)tmp) + 2)] == '\n')
		{
			*(tmp + 32) = '\1';
			return (1);
		}
		++((UL *)tmp)[2];
	}
	*(tmp + 32) = '\0';
	return (0);
}

static int		get_line(char *tmp, char **line)
{
	UL			len;

	if (!(*line = ft_strsub(tmp, *(((UL *)tmp) + 1),
							(len = ((UL *)tmp)[2] - *(((UL *)tmp) + 1)))))
		return (-1);
	*(((UL *)tmp) + 1) += len + 1;
	*(((UL *)tmp) + 2) = *(((UL *)tmp) + 1);
	if (*(tmp + 32) != '\2' && !(detect(tmp)))
	{
		ft_memmove(tmp + 33, &tmp[((UL *)tmp)[1]],
				   (len = *(((UL *)tmp) + 2) - *(((UL *)tmp) + 1)));
		*(((UL *)tmp) + 1) = 33;
		*(((UL *)tmp) + 2) = 33 + len;
		*(((UL *)tmp) + 3) = *(((UL *)tmp) + 2);
	}
	return (1);
}

static int		ft_read(char **tmp, const int fd, char **line)
{
	UL			stat;

	while ((stat = read(fd, &tmp[fd][((UL **)tmp)[fd][3]], BUFF_SIZE)) > 0)
	{
		((UL **)tmp)[fd][3] += stat;
		if (detect(tmp[fd]))
			return (get_line(tmp[fd], line));
		if ((*(((UL **)tmp)[fd] + 3) + BUFF_SIZE) >= *(((UL **)tmp)[fd]))
			if (!(ft_memadd(tmp, fd, *(((UL **)tmp)[fd] + 3) + BUFF_SIZE)))
				return (-1);
	}
	if (stat == 0 && tmp[fd][32] != '\2')
	{
		*(tmp[fd] + 32) = '\2';
		if (*(((UL **)tmp)[fd] + 2) != 33)
			return (get_line(tmp[fd], line));
		*line = ft_strnew(0);
	}
	return (stat);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp[MAX_FD];

	if (fd < 0 || fd > MAX_FD || !line ||
		(read(fd, *line, 0)) < 0 || BUFF_SIZE < 0)
		return (-1);
	if (tmp[fd] && *(tmp[fd] + 32) == '\1')
		return (get_line(tmp[fd], line));
	else if (!(tmp[fd]))
	{
		if (!(ft_memadd(tmp, fd, 33 + BUFF_SIZE)))
			return (-1);
	}
	else if ((*(((UL **)tmp)[fd] + 3) + BUFF_SIZE) >= *(((UL **)tmp)[fd]))
		if (!(ft_memadd(tmp, fd, ((*((((UL **)tmp)[fd]) + 3) + BUFF_SIZE)))))
			return (-1);
	return (ft_read(tmp, fd, line));
}
