/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:43:38 by tpetros           #+#    #+#             */
/*   Updated: 2023/06/01 13:43:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_julia(t_fractal *j)
{
	t_point	p;
	int		i;

	p.y = -1;
	while (++p.y < j->mlx.height)
	{
		p.x = -1;
		while (++p.x < j->mlx.width)
		{
			j->n_re = -1.5 * (p.x - j->mlx.width / 2) / \
				(j->zoom * j->mlx.width / 2) - j->m_x;
			j->n_im = (p.y - j->mlx.height / 2) / \
				(j->zoom * j->mlx.height / 2) - j->m_y;
			ft_ifs(j, &i);
			if (i == j->max_iter)
				j->mlx.addr[p.y * j->mlx.width + p.x] = 0;
			else
				j->mlx.addr[p.y * j->mlx.width + p.x] = j->color * (i >> 2);
		}
	}
}

void	ft_julia(t_fractal *j)
{
	ft_init_julia(j);
	ft_draw_julia(j);
	mlx_put_image_to_window(j->mlx.ptr, j->mlx.mlx_win, j->mlx.img, 0, 0);
	mlx_hook(j->mlx.mlx_win, 17, 1L << 17, ft_exit, j);
	mlx_key_hook(j->mlx.mlx_win, ft_key_events_mandel, j);
	mlx_mouse_hook(j->mlx.mlx_win, ft_mouse_events, j);
	mlx_loop(j->mlx.ptr);
}
