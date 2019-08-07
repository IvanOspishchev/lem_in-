/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:17:25 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 15:02:33 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t			i;

	i = -1;
	if (source == dest || n == 0)
		return (dest);
	while (++i < n)
		*((unsigned char *)dest + i) = *((unsigned char *)source + i);
	return (dest);
}
