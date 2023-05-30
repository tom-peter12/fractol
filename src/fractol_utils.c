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

int	ft_ratio(int width, int height)
{
	double	ratio;

	ratio = (double) width / (double) height;
	if (ratio > 1.7 || ratio < 1.2)
		return (1);
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
