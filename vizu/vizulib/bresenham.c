/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:01:05 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:06:03 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

static int		delta(t_room *d0, t_room *d1, int *delx, int *dely)
{
	int			col;

	*delx = (d1->x - d0->x > 0) ? (d1->x - d0->x) : (d0->x - d1->x);
	*dely = (d1->y - d0->y > 0) ? (d1->y - d0->y) : (d0->y - d1->y);
	if (d1->color == 849467 && d0->color == 849467)
		col = 849467;
	else
		col = 16777215;
	return (col);
}

static void		ft_dir(int *diry, int *dirx, t_room *d0, t_room *d1)
{
	*diry = (d0->y < d1->y) ? 1 : -1;
	*dirx = (d0->x < d1->x) ? 1 : -1;
}

void			ft_bresenham(t_room *d0, t_room *d1, t_mlx *mlx)
{
	int			delx;
	int			dely;
	int			diry;
	int			dirx;

	mlx->col = delta(d0, d1, &delx, &dely);	
	ft_dir(&diry, &dirx, d0, d1);
	mlx->err = delx - dely;
	while (d0->x != d1->x || d0->y != d1->y)
	{
		mlx_pixel_put(mlx->ptr, mlx->wind, d0->x, d0->y, mlx->col);
		mlx->derr = mlx->err * 2;
		if (mlx->derr > -dely)
		{
			mlx->err -= dely;
			d0->x += dirx;
		}
		if (mlx->derr < delx)
		{
			mlx->err += delx;
			d0->y += diry;
		}
	}
}
