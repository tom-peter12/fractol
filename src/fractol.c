/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:18:55 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/08 17:18:56 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_ratio(int width, int height)
{
	double	ratio;

	ratio = (double) width / (double) height;
	if (ratio > 1.5 || ratio < 1.0)
		return (0);
	return (1);
}

int	ft_check_params(int ac, char **av)
{
	t_fractal	f;

	f.mlx.width = ft_atoi(av[2]);
	f.mlx.height = ft_atoi(av[3]);
	if (ac == 4 && (ft_strcmp(av[1], "m") == 0)
		&& ft_ratio(f.mlx.width, f.mlx.height))
	{
		ft_mandel(&f);
		return (1);
	}
	return (0);
}

void	ft_display_options(void)
{
	ft_putstr("Usage: ./fractol [mj] [r i]\n");
	ft_putstr("m : Mandelbrot Set\n");
	ft_putstr("j : Julia Set [r i]\n");
	ft_putstr("Where -2 >= (r, i) =< 2\n");
	exit(ERROR);
}

int	main(int argc, char *argv[])
{
	if (!ft_check_params(argc, argv))
		ft_display_options();
	return (0);
}
