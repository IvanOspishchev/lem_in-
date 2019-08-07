/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:49:33 by hstiv             #+#    #+#             */
/*   Updated: 2019/01/14 15:14:04 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*s;

	if (!(s = malloc(sizeof(*s) * (size))))
		return (NULL);
	return (ft_memset(s, 0, size));
}
