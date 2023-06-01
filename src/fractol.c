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

void	ft_start_draw(int ac, char **av, t_fractal *f)
{
	f->mlx.width = ft_atof(av[2]);
	f->mlx.height = ft_atof(av[3]);
	if (ac == 4 && !ft_strcmp(av[1], "m"))
	{
		f->flag = 2;
		ft_mandel(f);
	}
	else if (ac == 6 && (!ft_strcmp(av[1], "j")))
	{
		f->flag = 3;
		f->c_re = ft_atof(av[4]);
		f->c_im = ft_atof(av[5]);
		ft_julia(f);
	}
	else if (ac == 4 && (!ft_strcmp(av[1], "b")))
	{
		f->flag = 1;
		ft_mandel(f);
	}
}

int	ft_check_params(int ac, char **av)
{
	if (ac < 4)
		return (NOT_ENOUGH_PARAMS);
	else if (!ft_strcmp(av[1], "m") && ac > 4)
		return (TOO_MANY_ARGUMENTS_M);
	else if (!ft_strcmp(av[1], "b") && ac > 4)
		return (TOO_MANY_ARGUMENTS_B);
	else if (!ft_strcmp(av[1], "j") && ac < 6)
		return (TOO_FEW_ARGUMENTS_J);
	else if (!ft_strcmp(av[1], "j") && ac > 6)
		return (TOO_MANY_ARGUMENTS_J);
	else if (ft_validate_dim(ft_atoi(av[2]), ft_atoi(av[3])))
		return (ASPECT_RATIO_NOT_GOOD);
	else if (ac == 6 && ft_valid_inp(av))
		return (INVALID_JULIA_INPUT);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal	f;

	ft_display_error(ft_check_params(argc, argv));
	ft_start_draw(argc, argv, &f);
	return (0);
}
