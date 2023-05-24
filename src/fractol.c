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

int	ft_valid_jul(char *str)
{
	(void) str;
	return (1);
}

int	ft_check_params(int ac, char **av)
{
	t_fractal	*f;

	if (ac == 2 && (ft_strcmp(av[1], "-m") == 0))
	{
		ft_draw_mandel(f);
		return (1);
	}
	else if(ac == 4 && (ft_strcmp(av[1], "-j") == 0)
		&& (ft_valid_jul(av[2]) && ft_valid_jul(av[3])))
	{
		ft_draw_julia(f, ft_atof(av[2]), ft_atof(av[3]));
		return (1);
	}
	return (0);
}

void	ft_display_options(void)
{
	ft_putstr("Usage: ./fractol [-mj] [r i]\n");
	ft_putstr("m : Mandelbrot Set\n");
	ft_putstr("j : Julia Set [r i]\n");
	ft_putstr("Where -2 >= (r, i) =< 2\n");
	exit(ERROR);
}

int	main(int argc, char *argv[])
{
	if (ft_check_params(argc, argv))
		ft_display_options();
	return (0);
}
