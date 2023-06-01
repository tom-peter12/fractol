/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:01 by tpetros           #+#    #+#             */
/*   Updated: 2022/10/15 16:57:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_set_sign(const char *str, int i, int *sign)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	number;
	int		c;
	int		sign;

	i = 0;
	number = 0;
	c = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (0);
	i = i + ft_set_sign(str, i, &sign);
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		c++;
		i++;
	}
	if (sign * number > 2147483647 || sign * number < -2147483648 || c > 10)
		return (-1);
	return ((int )(number * sign));
}
