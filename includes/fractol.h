/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:46:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/08 16:46:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft/libft.h"
#include "../mlx/mlx.h"

#define ERROR -1

typedef struct		s_fmlx
{
	void			*ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_fmlx;

typedef struct		s_point
{
	int	x;
	int y;
}					t_point;

typedef struct		s_fractal
{
	t_fmlx			mlx;
	t_point			p;
	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;
	double			oldre;
	double			oldim;
	double			zoom;
	double			m_x;
	double			m_y;
	int				max_iter;
	char			freeze;
}					t_fractal;

int		ft_check_params(int ac, char **av);
void	ft_mandel(t_fractal *f, int width, int height);
void	ft_init_mandel(t_fractal *f, int width, int height);

#endif