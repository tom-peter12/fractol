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
#include <math.h>

#define ERROR -1
#define NOT_ENOUGH_PARAMS 1
#define TOO_MANY_ARGUMENTS_M 2
#define TOO_FEW_ARGUMENTS_J 3
#define TOO_MANY_ARGUMENTS_J 4
#define ASPECT_RATIO_NOT_GOOD 5


typedef struct		s_fmlx
{
	void			*ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
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
	double			n_re;
	double			n_im;
	double			o_re;
	double			o_im;
	double			zoom;
	double			m_x;
	double			m_y;
	int				max_iter;
	char			freeze;
	int				color;
}					t_fractal;

int		ft_check_params(int ac, char **av, t_fractal *f);
void	ft_mandel(t_fractal *f);
void	ft_init_mandel(t_fractal *m);
int		ft_key_events_mandel(int keycode, t_fractal *m);
int		ft_mouse_events_m(int mousecode, int x, int y, t_fractal *m);
void	ft_color_m(t_fractal *m);
int		ft_exit_m(t_fractal *m);
void	ft_set_zero(double *nre, double *nim);
void	ft_mandel(t_fractal *m);
void	ft_draw_mandel(t_fractal *m);
int		ft_ratio(int width, int height);
void	ft_display_options(void);


void	ft_draw_julia(t_fractal *j);
void	ft_juia(t_fractal *j, char **av);
void	ft_init_julia(t_fractal *j, char **av);
void	ft_ifs(t_fractal *m, int *i);

#endif