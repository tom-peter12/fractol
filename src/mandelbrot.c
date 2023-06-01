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
			m->c_re = 1.5 * (p.x - m->mlx.width / 2) / \
				(0.5 * m->zoom * m->mlx.width) - m->m_x;
			m->c_im = (p.y - m->mlx.height / 2) / \
				(0.5 * m->zoom * m->mlx.height) - m->m_y;
			ft_set_zero(&(m->n_re), &(m->n_im));
			ft_ifs(m, &i);
			if (i == m->max_iter)
				m->mlx.addr[p.y * m->mlx.width + p.x] = 0;
			else
				m->mlx.addr[p.y * m->mlx.width + p.x] = m->color * i;
		}
	}
}

void	ft_mandel(t_fractal *m)
{
	ft_init_mandel(m);
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	mlx_hook(m->mlx.mlx_win, 17, 1L << 17, ft_exit, m);
	mlx_key_hook(m->mlx.mlx_win, ft_key_events_mandel, m);
	mlx_mouse_hook(m->mlx.mlx_win, ft_mouse_events, m);
	mlx_loop(m->mlx.ptr);
}
