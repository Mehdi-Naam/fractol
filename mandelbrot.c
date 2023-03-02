/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:39:44 by enaam             #+#    #+#             */
/*   Updated: 2023/02/26 13:37:50 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_mandelbrot(t_frcl	*mlx, double md_r, double md_i)
{
	mlx->it = 0;
	mlx->c_r = md_r;
	mlx->c_i = md_i;
	while (((md_r * md_r) + (md_i * md_i)) < 4 && mlx->it < 80)
	{
		mlx->tmp_r = md_r;
		mlx->tmp_i = md_i;
		md_r = (mlx->tmp_r * mlx->tmp_r) - (mlx->tmp_i * mlx->tmp_i) + mlx->c_r;
		md_i = (2 * mlx->tmp_r * mlx->tmp_i) + mlx->c_i;
		mlx->it++;
	}
	return (get_color((double)mlx->it / 80, mlx->i));
}

void	mand(t_frcl *mlx)
{	
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->color = ft_mandelbrot(mlx, ft_cwfs_x(mlx->x, mlx),
					ft_cwfs_y(mlx->y, mlx));
			my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
