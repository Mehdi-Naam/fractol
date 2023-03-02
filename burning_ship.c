/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:52:40 by enaam             #+#    #+#             */
/*   Updated: 2023/02/19 20:43:40 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	burning_ship(t_frcl *mlx, double bs_r, double bs_i)
{
	mlx->it = 0;
	mlx->c_r = bs_r;
	mlx->c_i = bs_i;
	while ((bs_r * bs_r) + (bs_i * bs_i) < 4.0 && mlx->it < 80)
	{
		bs_r = ft_abs(bs_r);
		bs_i = ft_abs(bs_i);
		mlx->tmp_r = bs_r;
		mlx->tmp_i = bs_i;
		bs_r = (mlx->tmp_r * mlx->tmp_r) - (mlx->tmp_i * mlx->tmp_i) + mlx->c_r;
		bs_i = 2 * mlx->tmp_r * mlx->tmp_i + mlx->c_i;
		mlx->it++;
	}
	return (get_color((double)mlx->it / 80, mlx->i));
}

void	burning(t_frcl *mlx)
{
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			mlx->color = burning_ship(mlx, ft_cwfs_x(mlx->x, mlx),
					ft_cwfs_y(mlx->y, mlx));
			my_mlx_pixel_put(mlx, mlx->x, mlx->y, mlx->color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
