/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:04:49 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:22 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizulib.h"

void				putman(t_mlx *mlx)
{
	t_room			**adj;
	int				i;
	int				color;
	int				l;

	l = mlx->lem->rooms_cnt;
	i = 0;
	adj = mlx->lem->adj;
	while (adj[i])
	{
		if (adj[i] == mlx->lem->begin)
			color = mlx->blue;
		else if (adj[i] == mlx->lem->end)
			color = mlx->yellow;
		else
			color = mlx->white;
		
		mlx_string_put(mlx->ptr, mlx->wind, 5,
			adj[i]->cor + mlx->cor, color, adj[i]->name);
		i++;
	}
}

int					ft_close(void *param)
{
	t_mlx			*tmp;

	tmp = (t_mlx *)param;
	exit(0);
}

void				run_window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->wind = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, VIZU);
	mlx_hook(mlx->wind, 17, (1L << 17), ft_close, mlx);
	mlx_hook(mlx->wind, 2, 0, key_press, mlx);
	mlx_hook(mlx->wind, 5, 0, key_release, mlx);
	mlx_hook(mlx->wind, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->wind, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->wind, 5, 0, mouse_release, mlx);
	mappaint(mlx);
	putman(mlx);
	mlx_loop(mlx->ptr);
}
