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

// int	ft_check_params(int ac, char **av, t_fractal *f)
// {
// 	if (ac < 4)
// 		return (NOT_ENOUGH_PARAMS);
// 	else if (ft_strcmp(av[1], "m") && ac > 4)
// 		return (TOO_MANY_ARGUMENTS_M);
// 	else if (ft_strcmp(av[1], "j") && ac < 6)
// 		return (TOO_FEW_ARGUMENTS_J);
// 	else if (ft_strcmp(av[1], "j") && ac > 6)
// 		return (TOO_MANY_ARGUMENTS_J);
// 	else if (!ft_ratio(f->mlx.width, f->mlx.height))
// 		return (ASPECT_RATIO_NOT_GOOD);
// 	return (0);
// }

int	ft_drawing_fractals(int ac, char **av, t_fractal *f)
{
	if (!ft_strcmp(av[1], "m"))
	{
		ft_mandel(f);
		return (1);
	}
	else if (ac == 6 && (!ft_strcmp(av[1], "j")))
	{
		ft_juia(f, av);
		return (1);
	}
	return (0);
}

int	ft_validate_dim(int width, int height)
{
	if ((width >= 1000 || width < 200) && (height < 200 || height > 800))
		return (1);
	if (ft_ratio(width, height))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractal	f;
	int			width;
	int			height;


	if (argc >= 4)
	{
		width = ft_atoi(argv[2]);
		height = ft_atoi(argv[3]);
		if (ft_validate_dim(width, height))
			ft_display_options();
		else
		{
			f.mlx.width = width;
			f.mlx.height = height;
		}
	}
	if (!ft_drawing_fractals(argc, argv, &f))
		ft_display_options();
	return (0);
}
