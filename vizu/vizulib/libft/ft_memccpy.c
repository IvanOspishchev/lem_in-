/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:22:39 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/13 15:09:34 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	if (!(dest || source))
		return (NULL);
	while (n--)
	{
		*(unsigned char*)dest = *(unsigned char*)source;
		if (*(unsigned char*)dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		source++;
	}
	return (NULL);
}
