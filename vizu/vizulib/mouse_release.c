/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:03:38 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:29 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

int					mouse_release(int button, int x, int y, t_mlx *param)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		param->left_mouse = 0;
		if (param->mv)
			param->mv = 0;
	}
	if (button == 2)
	{
		param->right_mouse = 0;
		if (param->sl)
			param->sl = 0;
	}
	mlx_clear_window(param->ptr, param->wind);
	mappaint(param);
	putman(param);
	return (0);
}
