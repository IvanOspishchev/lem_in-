/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:50:38 by hstiv             #+#    #+#             */
/*   Updated: 2018/12/31 13:43:34 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_atoi_if(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

static int			ft_atoi_maker(int sign, const char *n)
{
	int				res;
	int				check;

	res = 0;
	check = 0;
	while (48 <= *n && *n <= 57)
	{
		check = res;
		res *= 10;
		if (check != res / 10)
			return (ft_atoi_if(sign));
		res += *n - '0';
		n++;
		if (res < 0)
			return (ft_atoi_if(sign));
	}
	return (res * sign);
}

int					ft_atoi(const char *n)
{
	int				sign;

	sign = 1;
	while ((9 <= *n && *n <= 13) || *n == 32)
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	return (ft_atoi_maker(sign, n));
}
