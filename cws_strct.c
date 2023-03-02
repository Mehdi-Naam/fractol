/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cws_strct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:07:25 by enaam             #+#    #+#             */
/*   Updated: 2023/02/28 22:58:09 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	f_frcl(t_frcl *data)
{
	data->from_julia = 0;
	data->x = 0;
	data->y = 0;
	data->it = 0;
	data->color = 0.0;
	data->c_r = -0.70;
	data->c_i = -0.38;
	data->tmp_r = 0.0;
	data->tmp_i = 0.0;
	data->aftr_x = 0;
	data->aftr_y = 0;
	data->n = 0.8;
	data->tran_x = 2.0;
	data->tran_y = 2.0;
	data->shll = (4.0 / WIDTH);
	data->pus = 1;
	data->i = 0;
}

double	ft_cwfs_x(double cws_x, t_frcl *mlx)
{
	return ((cws_x * mlx->shll) - mlx->tran_x);
}

double	ft_cwfs_y(double cws_y, t_frcl *mlx)
{
	return ((cws_y * mlx->shll) - mlx->tran_y);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] || s1[i])
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	return (1);
}
