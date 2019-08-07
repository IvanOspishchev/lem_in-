/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:08:32 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 15:07:30 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = ft_strlen(dst) + 1;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < i)
		return (size + ft_strlen(src));
	if (i < size)
		ft_strncat(dst, src, size - i);
	return ((i - 1) + ft_strlen(src));
}
