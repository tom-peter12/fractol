/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:49:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/30 15:49:52 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_init_mandel(t_fractal *m)
{
	m->mlx.ptr = mlx_init();
	m->mlx.mlx_win = mlx_new_window(m->mlx.ptr, m->mlx.width, m->mlx.height, \
		"MandelBrot Fractal");
	m->mlx.img = mlx_new_image(m->mlx.ptr, m->mlx.width, m->mlx.height);
	m->mlx.addr = (int *)mlx_get_data_addr(m->mlx.img, &(m->mlx.bpp), \
		&(m->mlx.line_length), &(m->mlx.endian));
	m->p.x = 0;
	m->p.y = 0;
	m->c_re = 0.0;
	m->c_im = 0.0;
	m->n_re = 0.0;
	m->n_im = 0.0;
	m->o_im = 0.0;
	m->o_re = 0.0;
	m->zoom = 1.0;
	m->m_x = 0;
	m->m_y = 0;
	m->max_iter = 20;
	m->color = 126;
}

void	ft_set_zero(double *nre, double *nim)
{
	*nre = 0;
	*nim = 0;
}
