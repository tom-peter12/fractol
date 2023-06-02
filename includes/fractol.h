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

# include "libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define ERROR -1
# define NOT_ENOUGH_PARAMS 1
# define TOO_MANY_ARGUMENTS_M 2
# define TOO_FEW_ARGUMENTS_J 3
# define TOO_MANY_ARGUMENTS_J 4
# define ASPECT_RATIO_NOT_GOOD 5
# define INVALID_JULIA_INPUT 6
# define TOO_MANY_ARGUMENTS_B 7
# define INVALID_FRACTAL_INSTRUCTION 8
# define RED "\x1b[31m"
# define NORMAL "\x1b[m"

typedef struct s_fmlx
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

typedef struct s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct s_fractal
{
	t_fmlx			mlx;
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
	int				flag;
	int				color;
}					t_fractal;

int		ft_check_params(int ac, char **av);
int		ft_valid_inp(char **av);
int		ft_validate_dim(int width, int height);
void	ft_mandel(t_fractal *f);
void	ft_init_mandel(t_fractal *m);
int		ft_key_events_mandel(int k_code, t_fractal *m);
int		ft_mouse_events(int mousecode, int x, int y, t_fractal *m);
void	ft_set_zero(double *n_re, double *n_im);
void	ft_mandel(t_fractal *m);
void	ft_draw_mandel(t_fractal *m);
int		ft_ratio(int width, int height);
void	ft_display_error(int n);
void	ft_draw_julia(t_fractal *j);
void	ft_julia(t_fractal *j);
void	ft_init_julia(t_fractal *j);
void	ft_ifs(t_fractal *m, int *i);
int		ft_exit(t_fractal *f);
int		create_trgb(int r, int g, int b);
void	ft_change_iter(t_fractal *f);

#endif