/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:40:23 by enaam             #+#    #+#             */
/*   Updated: 2023/02/20 15:42:04 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	julia(t_frcl *mlx, double jl_r, double jl_i)
{
	mlx->it = 0;
	while (((jl_r * jl_r) + (jl_i * jl_i)) < 4.0 && mlx->it < 80)
	{
		mlx->tmp_r = jl_r;
		mlx->tmp_i = jl_i;
		jl_r = (mlx->tmp_r * mlx->tmp_r) - (mlx->tmp_i * mlx->tmp_i) + mlx->c_r;
		jl_i = 2.0 * mlx->tmp_r * mlx->tmp_i + mlx->c_i;
		mlx->it++;
	}
	return (get_color((double)(mlx->it / 80.0), mlx->i));
}

void	joulia(t_frcl *mlx)
{
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->color = julia(mlx, ft_cwfs_x(mlx->x, mlx),
					ft_cwfs_y(mlx->y, mlx));
			my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color);
			mlx->y++;
		}	
		mlx->x++;
	}
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

int	mouse_move(int x, int y, t_frcl *mlx)
{
	if (mlx->from_julia == 1 && x < WIDTH && x > 0
		&& y < HEIGHT && y > 0 && mlx->pus == 1)
	{
		mlx->c_r = ft_cwfs_x(x, mlx);
		mlx->c_i = ft_cwfs_y(y, mlx);
		joulia(mlx);
	}
	return (0);
}
