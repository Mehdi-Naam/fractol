/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:50:12 by enaam             #+#    #+#             */
/*   Updated: 2023/02/21 21:14:55 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	flag(t_frcl *mlx)
{
	if (mlx->pus == 1)
		mlx->pus = 0;
	else
		mlx->pus = 1;
}

int	zoom(int button, int x, int y, t_frcl *mlx)
{
	mlx->aftr_x = ft_cwfs_x(x, mlx);
	mlx->aftr_y = ft_cwfs_y(y, mlx);
	if (button == 4)
	{
		mlx->shll *= mlx->n ;
		mlx->tran_x -= mlx->aftr_x - ft_cwfs_x(x, mlx);
		mlx->tran_y -= mlx->aftr_y - ft_cwfs_y(y, mlx);
	}
	else if (button == 5)
	{
		mlx->shll /= mlx->n;
		mlx->tran_x -= mlx->aftr_x - ft_cwfs_x(x, mlx);
		mlx->tran_y -= mlx->aftr_y - ft_cwfs_y(y, mlx);
	}
	else if (button == 1)
		flag(mlx);
	if (mlx->from_julia == -1)
		mand(mlx);
	else if (mlx->from_julia == 1)
		joulia(mlx);
	else if (mlx->from_julia == 0)
		burning(mlx);
	return (0);
}
