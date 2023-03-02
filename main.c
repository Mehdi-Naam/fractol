/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:33:56 by enaam             #+#    #+#             */
/*   Updated: 2023/02/28 22:58:20 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_close(t_frcl *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}

static void	check(t_frcl *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Fractol");
	if (!mlx->win)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_clear_window(mlx->ptr, mlx->win);
	}
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (!mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (mlx->from_julia == -1)
		mand(mlx);
	else if (mlx->from_julia == 0)
		burning(mlx);
	else if (mlx->from_julia == 1)
	{
		joulia(mlx);
		mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
	}
	mlx_hook(mlx->win, 2, 0, move, mlx);
	mlx_hook(mlx->win, 4, 0, zoom, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close, mlx);
	mlx_loop(mlx->ptr);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	display_error_msg(void)
{
	ft_putstr(RED);
	ft_putstr("Warnning syntax :\n");
	write(1, "\t\t", 2);
	ft_putstr(GREEN);
	ft_putstr("./fractol mandelbrot\n");
	write(1, "\t\t", 2);
	ft_putstr("./fractol julia\n");
	write(1, "\t\t", 2);
	ft_putstr("./fractol burning_ship\n");
	ft_putstr(WHITE);
}

int	main(int ac, char **av)
{
	t_frcl	data;

	if (ac == 1 || ac > 2)
	{
		display_error_msg();
		return (1);
	}
	if (ac == 2)
	{
		f_frcl(&data);
		if (ft_strcmp("julia", av[1]))
			data.from_julia = 1;
		else if (ft_strcmp("mandelbrot", av[1]))
			data.from_julia = -1;
		else if (ft_strcmp("burning_ship", av[1]))
			data.from_julia = 0;
		else
		{
			display_error_msg();
			exit(0);
		}
		check(&data);
	}
}
