/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:00:21 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/24 18:00:22 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_fractal *f, int width, int heigth)
{
	f->mlx.ptr = mlx_init();
	f->mlx.mlx_win = mlx_new_window(f->mlx.ptr, width, heigth, "MandelBrot Fractal");
	f->mlx.img = mlx_new_image(f->mlx.ptr, width, heigth);
	f->mlx.addr = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bits_per_pixel), &(f->mlx.line_length), &(f->mlx.endian));
	f->zoom = 1.0;
	f->c_im = 0.0;
	f->c_re = 0.0;
	f->p.x = 0;
	f->p.y = 0;
	f->max_iter = 100;
}

void	ft_set_zero(double *nre, double *nim, double *oldre, double *oldim)
{
	*nre = 0;
	*nim = 0;
	*oldre = 0;
	*oldim = 0;
}

void	ft_draw_mandel(t_fractal *m, int width, int height)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < height)
	{
		p.x = -1;
		while (++p.x < width)
		{
			m->c_re = 1.5 * (p.x - width / 2) / (0.5 * m->zoom * width) - m->m_x;
			m->c_im = (p.y - height / 2) / (0.5 * m->zoom * height) - m->m_y;
			ft_set_zero(&(m->z_re), &(m->z_im), &(m->oldre), &(m->oldim));
			i = -1;
			while (++i < m->max_iter)
			{
				m->oldre = m->z_re;
				m->oldim = m->z_im;
				m->z_re = m->oldre * m->oldre - m->oldim * m->oldim + m->c_re;
				m->z_im = 2 * m->oldre * m->oldim + m->c_im;
				if ((m->z_re * m->z_re + m->z_im * m->z_im) > 4)
					break ;
			}
			m->mlx.addr[p.y * width + p.x] = i == m->max_iter ? 0 : 1024 * i;
		}
	}
}

void	ft_mandel(t_fractal *f, int width, int height)
{
	ft_init_mandel(f, width, height);
	ft_draw_mandel(f, width, height);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.mlx_win, f->mlx.img, 0, 0);
	mlx_loop(f->mlx.ptr);
}
