/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:40:29 by enaam             #+#    #+#             */
/*   Updated: 2023/02/25 20:37:21 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"
# define HEIGHT 600
# define WIDTH 600

typedef struct s_frcl
{
	int		from_julia;
	int		x;
	int		y;
	int		i;
	int		pus;
	int		it;
	double	aftr_x;
	double	aftr_y;
	double	n;
	double	c_i;
	double	c_r;
	double	tmp_r;
	double	tmp_i;
	void	*ptr;
	void	*win;
	void	*img;
	void	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	double	shll;
	double	tran_y;
	double	tran_x;
}	t_frcl;

void	f_frcl(t_frcl *data);
void	my_mlx_pixel_put(t_frcl *data, int m, int z, int color);
int		get_color(double it, int i);
int		create_trgb(int t, int r, int g, int b);
double	ft_cwfs_x(double cws_x, t_frcl *mlx);
double	ft_cwfs_y(double cws_y, t_frcl *mlx);
int		move(int button, t_frcl *mlx);
int		zoom(int button, int x, int y, t_frcl *mlx);
void	joulia(t_frcl *mlx);
void	mand(t_frcl *mlx);
int		ft_strcmp(char *s1, char *s2);
int		mouse_move(int x, int y, t_frcl *mlx);
void	burning(t_frcl *mlx);

#endif