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

int	ft_valid(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		i++;
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.')
			flag++;
		if (flag == 2)
			return (1);
		i++;
	}
	if (i != ((int) ft_strlen(str)) || (str[0] == '+' && ft_strlen(str) == 1)
		|| (str[0] == '-' && ft_strlen(str) == 1))
		return (1);
	else
		return (0);
}

int	ft_valid_inp(char **av)
{
	double	one;
	double	two;

	if (ft_valid(av[4]) || ft_valid(av[5]))
		return (1);
	one = ft_atof(av[4]);
	two = ft_atof(av[5]);
	if ((one > 2.0 || one < -2.0) || (two > 2.0 || two < -2.0))
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
	if (ratio > 1.7 || ratio < 1.0)
		return (1);
	return (0);
}

void	ft_display_error(int n)
{
	if (n == 0)
		return ;
	ft_printf("\nUsage: ./fractol command [ARGUMENTS]\n\n");
	ft_printf("commands: \tm\t=>\tmandelbrot\n");
	ft_printf("\t\tj\t=>\tjulia\n");
	ft_printf("\t\tb\t=>\tburning ship\n\n");
	if (n == NOT_ENOUGH_PARAMS)
		ft_printf(RED"NOT_ENOUGH_PARAMS\n\n"NORMAL);
	else if (n == INVALID_FRACTAL_INSTRUCTION)
		ft_printf(RED"INVALID_FRACTAL_INSTRUCTION\n\n"NORMAL);
	else if (n == TOO_MANY_ARGUMENTS_M)
		ft_printf(RED"TOO_MANY_ARGUMENTS_MANDELBROT\n\n"NORMAL);
	else if (n == TOO_FEW_ARGUMENTS_J)
		ft_printf(RED"TOO_FEW_ARGUMENTS_JULIA\n\n"NORMAL);
	else if (n == TOO_MANY_ARGUMENTS_J)
		ft_printf(RED"TOO_MANY_ARGUMENTS_JULIA\n\n"NORMAL);
	else if (n == ASPECT_RATIO_NOT_GOOD)
		ft_printf(RED"ASPECT_RATIO_NOT_GOOD\n\n"NORMAL);
	else if (n == INVALID_JULIA_INPUT)
		ft_printf(RED"INVALID_JULIA_INPUT\n\n"NORMAL);
	else if (n == TOO_MANY_ARGUMENTS_B)
		ft_printf(RED"TOO_MANY_ARGUMENTS_BSHIP\n\n"NORMAL);
	exit(ERROR);
}
