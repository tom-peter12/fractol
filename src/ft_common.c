/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:46:24 by tpetros           #+#    #+#             */
/*   Updated: 2023/06/01 18:46:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_ifs(t_fractal *f, int *i)
{
	*i = -1;
	while (++(*i) < f->max_iter)
	{
		f->o_re = f->n_re;
		f->o_im = f->n_im;
		f->n_re = f->o_re * f->o_re - f->o_im * f->o_im + f->c_re;
		if (f->flag == 1)
			f->n_im = 2 * fabs(f->o_re * f->o_im) + f->c_im;
		else
			f->n_im = 2 * (f->o_re * f->o_im) + f->c_im;
		if ((f->n_re * f->n_re + f->n_im * f->n_im) > 4)
			break ;
	}
}

int	ft_exit(t_fractal *f)
{
	mlx_destroy_image(f->mlx.ptr, f->mlx.img);
	mlx_destroy_window(f->mlx.ptr, f->mlx.mlx_win);
	exit(1);
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_color(t_fractal *f)
{
	int	red;
	int	green;
	int	blue;

	red = (f->max_iter << 4) / (1 << f->color);
	green = (f->max_iter << 2) / (1 << f->color);
	blue = ((f->max_iter ^ f->color) << 3) % (1 << f->color);
	f->color = create_trgb(red, green, blue);
	if (f->color < 2)
		f->color = (255);
}

void	ft_change_iter(t_fractal *f)
{
	if (f->max_iter < 150)
		f->max_iter += 10;
	else if (f->max_iter >= 150)
		f->max_iter = 20;
}
