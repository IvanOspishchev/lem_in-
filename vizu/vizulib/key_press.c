/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:02:34 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:39 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		x_and_y(int keycode, t_mlx *param)
{
	if (keycode == 53)
		ft_close((void *)param);
	if (keycode == 13)
		param->y_add -= CON;
	if (keycode == 1)
		param->y_add += CON;
	if (keycode == 2)
		param->x_add += CON;
	if (keycode == 0)
		param->x_add -= CON;
	if (keycode == 3)
		param->fill += 1;
	if (keycode == 69)
		param->l += 0.1;
	if (keycode == 78)
		param->l -= 0.1;
	if (keycode == 259)
		param->cmnd = 1;
	if (keycode == 46)
		param->m += 1;
}

int				key_release(int keycode, t_mlx *param)
{
	if (keycode == 259)
	{
		param->cmnd = 0;
		param->cor = 0;
	}
	return (0);
}

int				key_press(int keycode, t_mlx *param)
{
	x_and_y(keycode, param);
	mlx_clear_window(param->ptr, param->wind);
	if (param->m % 2 == 0)
		give_color(param);
	if (param->m % 2 == 1)
		resert_color(param);
	mappaint(param);
	putman(param);
	return (0);
}
