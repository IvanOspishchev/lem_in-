/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 14:05:30 by hstiv             #+#    #+#             */
/*   Updated: 2018/12/31 13:48:17 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_memory(char const *s)
{
	int			l;

	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	return (l);
}

char			*ft_strtrim(char const *s)
{
	char		*s1;
	int			i;
	int			l;

	if (!s)
		return (NULL);
	i = -1;
	l = ft_memory(s);
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		l--;
	if (l < 0)
		l = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < l)
	{
		s1[i] = *s;
		s++;
	}
	s1[i] = '\0';
	return (s1);
}
