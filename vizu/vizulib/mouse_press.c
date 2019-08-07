/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:32 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:30 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void			mouse_for_everything(int button, t_mlx *param)
{
	if (param->left_mouse && button == 4)
		param->radius += 1;
	if (param->left_mouse && button == 5 && param->radius > 0)
		param->radius -= 1;
	if (param->right_mouse && button == 4)
		param->l += 0.1;
	if (param->right_mouse && button == 5 && param->l > 0)
		param->l -= 0.1;
	if (!param->right_mouse && !param->left_mouse && button == 4)
		param->cor += 5;
	if (!param->right_mouse && !param->left_mouse && button == 5)
		param->cor -= 5;
}

int					mouse_press(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
		param->left_mouse = 1;
	if (button == 2)
		param->right_mouse = 1;
	if (param->left_mouse && param->right_mouse)
	{
		param->x_add = x;
		param->y_add = y;
	}
	mouse_for_everything(button, param);
	mlx_clear_window(param->ptr, param->wind);
	putman(param);
	mappaint(param);
	return (0);
}
