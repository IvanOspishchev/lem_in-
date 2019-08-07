/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:12:48 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/23 14:40:00 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlenc(char const *s, char c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
