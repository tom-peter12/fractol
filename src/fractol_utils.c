/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:10:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/30 16:10:50 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_valid_inp(char **av)
{
	double	one;
	double	two;

	one = ft_atof(av[4]);
	two = ft_atof(av[5]);
	if ((one > 2.0 || one < -2.0) && (two > 2.0 || two < -2.0))
		return (1);
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

int	ft_ratio(int width, int height)
{
	double	ratio;

	ratio = (double) width / (double) height;
	if (ratio > 1.7 || ratio < 1.2)
		return (1);
	return (0);
}

void	ft_display_error(int n)
{
	if (n == 0)
		return ;
	else if (n == NOT_ENOUGH_PARAMS)
		ft_printf("NOT_ENOUGH_PARAMS\n");
	else if (n == TOO_MANY_ARGUMENTS_M)
		ft_printf("TOO_MANY_ARGUMENTS_M\n");
	else if (n == TOO_FEW_ARGUMENTS_J)
		ft_printf("TOO_FEW_ARGUMENTS_J\n");
	else if (n == TOO_MANY_ARGUMENTS_J)
		ft_printf("TOO_MANY_ARGUMENTS_J\n");
	else if (n == ASPECT_RATIO_NOT_GOOD)
		ft_printf("ASPECT_RATIO_NOT_GOOD\n");
	else if (n == INVALID_JULIA_INPUT)
		ft_printf("INVALID_JULIA_INPUT\n");
	else if (n == TOO_MANY_ARGUMENTS_B)
		ft_printf("TOO_MANY_ARGUMENTS_B\n");
	exit(ERROR);
}
