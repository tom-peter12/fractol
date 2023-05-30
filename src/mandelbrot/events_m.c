/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/30 15:49:24 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_exit_m(t_fractal *m)
{
	mlx_destroy_image(m->mlx.ptr, m->mlx.img);
	mlx_destroy_window(m->mlx.ptr, m->mlx.mlx_win);
	exit(1);
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_color_m(t_fractal *m)
{
	int red = (m->max_iter << 4) / (1 << m->color);
	int green = (m->max_iter << 2) / (1 << m->color);
	int blue = ((m->max_iter ^ m->color) << 3) % (1 << m->color);
	m->color = create_trgb(red, green, blue);
	if (m->color < 2)
		m->color = (255);
}

void	ft_change_iter(t_fractal *m)
{
	if (m->max_iter < 100)
		m->max_iter += 10;
	if (m->max_iter >= 100)
		m->max_iter = 20;
}

int	ft_mouse_events_m(int mousecode, int x, int y, t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	if (mousecode == 1 || mousecode == 4)
	{
		m->m_x += 0.002 * ((m->mlx.width / 2) - x) / m->zoom;
		m->m_y += 0.002 * ((m->mlx.height / 2) - y) / m->zoom;
		if (mousecode == 4)
			m->zoom *= 1.5;
	}
	if (mousecode == 5)
	{
		if (m->zoom < 1)
			m->zoom = 1;
		else
			m->zoom /= 1.5;
	}
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	return (0);
}

int	ft_key_events_mandel(int keycode, t_fractal *m)
{
	mlx_clear_window(m->mlx.ptr, m->mlx.mlx_win);
	if (keycode == 53)
		ft_exit_m(m);
	else if (keycode == 8)
		ft_color_m(m);
	else if (keycode == 34)
		ft_change_iter(m);
	ft_draw_mandel(m);
	mlx_put_image_to_window(m->mlx.ptr, m->mlx.mlx_win, m->mlx.img, 0, 0);
	return (0);
}
