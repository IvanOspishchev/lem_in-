/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:31:45 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 13:48:37 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memmove(void *dest, const void *source, size_t len)
{
	size_t			i;

	if (source == dest)
		return (dest);
	if (source < dest)
	{
		i = len;
		while (i-- > 0)
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
			i++;
		}
	}
	return (dest);
}
