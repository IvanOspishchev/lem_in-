/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:51 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:57 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void			others(t_mlx *mlx)
{
	mlx->l = 0.1;
	mlx->err = 0;
	mlx->derr = 0;
	mlx->left_mouse = 0;
	mlx->right_mouse = 0;
	mlx->mv = 0;
	mlx->fill = 1;
	mlx->cor = 0;
	mlx->cmnd = 0;
	mlx->m = 1;
	mlx->col = 0;
}

t_mlx				*ft_newmlx(void)
{
	t_mlx			*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (mlx)
	{
		mlx->wind = NULL;
		mlx->ptr = NULL;
		mlx->lem = NULL;
		mlx->x_add = 0;
		mlx->y_add = 0;
		mlx->radius = 5;
		mlx->blue = 4518094;
		mlx->red = 16124995;
		mlx->green = 849467;
		mlx->yellow = 16776960;
		mlx->white = 16777215;
		others(mlx);
	}
	return (mlx);
}
