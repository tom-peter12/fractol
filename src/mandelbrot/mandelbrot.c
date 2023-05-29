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

#include "../../includes/fractol.h"

void	ft_init_mandel(t_fractal *m)
{
	m->mlx.ptr = mlx_init();
	m->mlx.mlx_win = mlx_new_window(m->mlx.ptr, m->mlx.width, m->mlx.height, \
		"MandelBrot Fractal");
	m->mlx.img = mlx_new_image(m->mlx.ptr,m->mlx.width, m->mlx.height);
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp),\
		&(m->mlx.line_length), &(m->mlx.endian));
	m->zoom = 1.0;
	m->c_im = 0.0;
	m->c_re = 0.0;
	m->n_re = 0.0;
	m->n_im = 0.0;
	m->o_im = 0.0;
	m->o_re = 0.0;
	m->p.x = 0;
	m->p.y = 0;
	m->color = 255;
	m->max_iter = 100;
}

void	ft_set_zero(double *nre, double *nim)
{
	*nre = 0;
	*nim = 0;
}

void	ft_IFS(t_fractal *m, int *i)
{
	*i = -1;
	while (++(*i) < m->max_iter)
	{
		m->o_re = m->n_re;
		m->o_im = m->n_im;
		m->n_re = pow(m->o_re, 2) - pow(m->o_im, 2) + m->c_re;
		m->n_im = 2 * m->o_re * m->o_im + m->c_im;
		if ((pow(m->n_re, 2) + pow(m->n_im, 2)) > 4)
			break ;
	}
}

void	ft_draw_mandel(t_fractal *m)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < m->mlx.height)
	{
		p.x = -1;
		while (++p.x < m->mlx.width)
		{
			m->c_re = 1.5 * (p.x - m->mlx.width / 2) / (0.5 * m->zoom * m->mlx.width) - m->m_x;
			m->c_im = (p.y - m->mlx.height / 2) / (0.5 * m->zoom * m->mlx.height) - m->m_y;
			ft_set_zero(&(m->n_re), &(m->n_im));
			ft_IFS(m, &i);
			if (i == m->max_iter)
				m->mlx.addr[p.y * m->mlx.width + p.x] = 0;
			else
				m->mlx.addr[p.y * m->mlx.width + p.x] = m->color * i;
		}
	}
}

void	ft_color_m(t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	m->color = (m->color >> 2);
	if (m->color < 2)
		m->color = (255);
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
}

int	ft_exit_m(t_fractal *m)
{
	mlx_destroy_image(m->mlx.ptr, m->mlx.img);
	exit(1);
}

int	ft_key_events_mandel(int keycode, t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	if (keycode == 53)
		ft_exit_m(m);
	else if (keycode == 8)
		ft_color_m(m);
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	return (0);
}

int		ft_mouse_events_m(int mousecode, int x, int y, t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	if (mousecode == 1 || mousecode == 4)
	{
		m->m_x += 0.002 * ((m->mlx.width / 2) - x) / m->zoom;
		m->m_y += 0.002 * ((m->mlx.height / 2) - y) / m->zoom;
		if (mousecode == 4)
			m->zoom *= 2;
	}
	if (mousecode == 5)
		m->zoom = m->zoom <= 1 ? 1 : m->zoom / 2;
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	return (0);
}

void	ft_mandel(t_fractal *m)
{
	ft_init_mandel(m);
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	mlx_hook(m->mlx.mlx_win, 17, 1L<<17, ft_exit_m, m);
	mlx_key_hook(m->mlx.mlx_win, ft_key_events_mandel, m);
	mlx_mouse_hook(m->mlx.mlx_win, ft_mouse_events_m, m);
	mlx_loop(m->mlx.ptr);
}
