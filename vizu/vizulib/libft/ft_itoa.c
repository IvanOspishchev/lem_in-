/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:42:37 by hstiv             #+#    #+#             */
/*   Updated: 2018/12/31 13:46:18 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			ft_itoa_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char				*ft_itoa(int n)
{
	char			*s;
	char			res[11];
	int				i;
	int				sign;
	int				l;

	i = 0;
	l = -1;
	sign = ft_itoa_sign(n);
	ft_bzero(res, 11);
	while (sign * n > 9 || sign * n < 0)
	{
		res[i++] = '0' + sign * (n % 10);
		n = n / 10;
	}
	res[i++] = '0' + sign * n;
	if (sign < 0)
		res[i++] = '-';
	s = (char *)malloc(sizeof(char) * (ft_strlen(res) + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	while (i--)
		s[i] = res[++l];
	return (s);
}
