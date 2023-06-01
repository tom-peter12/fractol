/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:36:49 by tpetros           #+#    #+#             */
/*   Updated: 2023/06/01 19:36:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_fractal *m)
{
	m->mlx.ptr = mlx_init();
	if (m->flag == 2)
		m->mlx.mlx_win = mlx_new_window(m->mlx.ptr, m->mlx.width, m->mlx.height,
				"MandelBrot Fractal");
	else
		m->mlx.mlx_win = mlx_new_window(m->mlx.ptr, m->mlx.width, m->mlx.height,
				"Burning Ship Fractal");
	m->mlx.img = mlx_new_image(m->mlx.ptr, m->mlx.width, m->mlx.height);
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp), \
		&(m->mlx.line_length), &(m->mlx.endian));
	m->c_re = 0.0;
	m->c_im = 0.0;
	m->n_re = 0.0;
	m->n_im = 0.0;
	m->o_im = 0.0;
	m->o_re = 0.0;
	m->zoom = 1.0;
	m->m_x = 0;
	m->m_y = 0;
	m->max_iter = 50;
	m->color = 255;
}

void	ft_init_julia(t_fractal *j)
{
	j->mlx.ptr = mlx_init();
	j->mlx.mlx_win = mlx_new_window(j->mlx.ptr, j->mlx.width, j->mlx.height, \
		"Julia Fractal");
	j->mlx.img = mlx_new_image(j->mlx.ptr, j->mlx.width, j->mlx.height);
	j->mlx.addr = (int *)mlx_get_data_addr(j->mlx.img, &(j->mlx.bpp), \
		&(j->mlx.line_length), &(j->mlx.endian));
	j->n_re = 0.0;
	j->n_im = 0.0;
	j->o_im = 0.0;
	j->o_re = 0.0;
	j->zoom = 1.0;
	j->m_x = 0;
	j->m_y = 0;
	j->max_iter = 50;
	j->color = 255;
}

void	ft_set_zero(double *n_re, double *n_im)
{
	*n_re = 0;
	*n_im = 0;
}
