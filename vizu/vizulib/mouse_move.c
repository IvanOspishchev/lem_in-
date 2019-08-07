/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:24 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:31 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int					mouse_move(int x, int y, t_mlx *param)
{
	if (param->left_mouse && param->right_mouse)
	{
		param->x_add = x;
		param->y_add = y;
		param->mv = 1;
	}
	mlx_clear_window(param->ptr, param->wind);
	mappaint(param);
	putman(param);
	return (0);
}
