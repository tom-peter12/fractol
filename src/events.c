/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/30 15:49:24 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_move(t_fractal *f, int k_code)
{
	if (k_code == 126)
		f->m_y = f->m_y + 0.5 / f->zoom;
	else if (k_code == 125)
		f->m_y = f->m_y - 0.5 / f->zoom;
	else if (k_code == 124)
		f->m_x = f->m_x + 0.5 / f->zoom;
	else if (k_code == 123)
		f->m_x = f->m_x - 0.5 / f->zoom;
}

void	ft_clean(t_fractal *f)
{
	f->zoom = 1.0;
	f->m_x = 0.0;
	f->m_y = 0.0;
	f->color = 0x31104a;
	f->max_iter = 50;
}

int	ft_mouse_events(int mousecode, int x, int y, t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	if (mousecode == 1 || mousecode == 4)
	{
		m->m_x += 0.00113 * ((m->mlx.width / 2) - x) / m->zoom;
		m->m_y += 0.00113 * ((m->mlx.height / 2) - y) / m->zoom;
		if (mousecode == 4)
			m->zoom *= 1.5;
	}
	if (mousecode == 5)
	{
		if (m->zoom > 0.5)
			m->zoom /= 1.5;
	}
	if (m->flag == 2 || m->flag == 1)
		ft_draw_mandel(m);
	else if (m->flag == 3)
		ft_draw_julia(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	return (0);
}

int	ft_key_events_mandel(int k_code, t_fractal *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.mlx_win);
	if (k_code == 53)
		ft_exit(f);
	else if (k_code == 34)
		ft_change_iter(f);
	else if (k_code == 126 || k_code == 125 || k_code == 124 || k_code == 123)
		ft_move(f, k_code);
	else if (k_code == 29)
		ft_clean(f);
	if (f->flag == 2 || f->flag == 1)
		ft_draw_mandel(f);
	else if (f->flag == 3)
		ft_draw_julia(f);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.mlx_win, f->mlx.img, 0, 0);
	return (0);
}
