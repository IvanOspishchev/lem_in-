/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:17:22 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 15:07:27 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char				*ft_strstr(const char *s1, const char *s2)
{
	size_t			i;

	i = ft_strlen(s2);
	while (*s1 || !*s2)
		if (*s2 == '\0')
			return ((char *)s1);
		else if (!(ft_strncmp(s1++, s2, i)))
			return ((char *)s1 - 1);
	return (NULL);
}
