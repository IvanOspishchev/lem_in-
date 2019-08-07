/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:35:35 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/23 14:39:35 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_freeder(char **argv, size_t i)
{
	while (i)
	{
		ft_memdel((void**)&argv[i]);
		i--;
	}
	ft_memdel((void**)argv);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**argv;
	size_t			i;
	size_t			l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_count_char(s, c);
	if (!(argv = (char **)malloc(sizeof(char**) * (l + 1))))
		return (NULL);
	while (l--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(argv[i] = ft_strsub(s, 0, ft_strlenc(s, c))))
		{
			ft_freeder(argv, i);
			return (NULL);
		}
		s += ft_strlenc(s, c);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
