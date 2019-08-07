/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:12 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:06:02 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static void		err_mani(int *err, int *y, int *x)
{
	if (*err <= 0)
	{
		(*y) += 1;
		*err += 2 * (*y) + 1;
	}
	if (*err > 0)
	{
		*x -= 1;
		*err -= 2 * (*x) + 1;
	}
}

void			circle(int x0, int y0, t_mlx *mlx, int color)
{
	int			x;
	int			y;
	int			err;

	x = mlx->radius;
	y = 0;
	err = 0;
	while (x >= y)
	{
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 + x, y0 + y, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 + y, y0 + x, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 - y, y0 + x, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 - x, y0 + y, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 - x, y0 - y, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 - y, y0 - x, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 + y, y0 - x, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, x0 + x, y0 - y, color);
		err_mani(&err, &y, &x);
	}
}

void			fcircle_func(int x0, int y0, t_mlx *mlx, int color)
{
	int			i;

	i = x0 - mlx->x;
	while (i <= x0 + mlx->x)
	{
		mlx_pixel_put(mlx->ptr, mlx->wind, i, y0 + mlx->y, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, i, y0 - mlx->y, color);
		i++;
	}
	i = x0 - mlx->y;
	while (i <= x0 + mlx->y)
	{
		mlx_pixel_put(mlx->ptr, mlx->wind, i, y0 + mlx->x, color);
		mlx_pixel_put(mlx->ptr, mlx->wind, i, y0 - mlx->x, color);
		i++;
	}
	mlx->y++;
}

void			fcircle(int x0, int y0, t_mlx *mlx, int color)
{
	int			xchange;
	int			ychange;
	int			radius_error;

	mlx->x = mlx->radius;
	mlx->y = 0;
	xchange = 1 - (mlx->radius << 1);
	ychange = 0;
	radius_error = 0;
	while (mlx->x >= mlx->y)
	{
		fcircle_func(x0, y0, mlx, color);
		radius_error += ychange;
		ychange += 2;
		if (((radius_error << 1) + xchange) > 0)
		{
			mlx->x--;
			radius_error += xchange;
			xchange += 2;
		}
	}
}
