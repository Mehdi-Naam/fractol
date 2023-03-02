/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:31:25 by enaam             #+#    #+#             */
/*   Updated: 2023/02/26 13:54:36 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(double it, int i)
{
	int	red;
	int	blue;
	int	green;

	red = it * (1 - it) * (1 - it) * 1500;
	blue = it * (1 - it) * (1 - it) * (1 - it) * 1500;
	green = (1 - it) *(1 - it) * (1 - it) * (1 - it) * it * (1 - it) * 1500;
	if (i % 5 == 0)
		return (create_trgb(0, red, green, blue));
	if (i % 5 == 1)
		return (create_trgb(0, blue, green, red));
	if (i % 5 == 2)
		return (create_trgb(0, blue, red, green));
	if (i % 5 == 3)
		return (create_trgb(0, green, red, blue));
	return (create_trgb(0, red, blue, green));
}

void	my_mlx_pixel_put(t_frcl *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
