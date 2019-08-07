/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:25:09 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/14 14:52:39 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = ft_strlen(s2);
	while (!*s2 || (*s1 && i <= len--))
		if (*s2 == '\0')
			return ((char *)s1);
		else if (!(ft_strncmp(s1++, s2, i)))
			return ((char *)s1 - 1);
	return (NULL);
}
