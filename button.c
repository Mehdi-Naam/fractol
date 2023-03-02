/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:00:47 by enaam             #+#    #+#             */
/*   Updated: 2023/02/20 15:43:56 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	move(int button, t_frcl *mlx)
{
	if (button == 48)
		mlx->i++;
	else if (button == 123)
		mlx->tran_x -= 5.0 * mlx->shll;
	else if (button == 124)
		mlx->tran_x += 5.0 * mlx->shll;
	else if (button == 126)
		mlx->tran_y -= 5.0 * mlx->shll;
	else if (button == 125)
		mlx->tran_y += 5.0 * mlx->shll;
	else if (button == 53)
		exit(0);
	if (mlx->from_julia == -1)
		mand(mlx);
	else if (mlx->from_julia == 1)
		joulia(mlx);
	else if (mlx->from_julia == 0)
		burning(mlx);
	return (0);
}
