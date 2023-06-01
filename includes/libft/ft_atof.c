/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:14:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/05/23 16:14:36 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int(char *str, int *i)
{
	char	*new;

	*i = 0;
	while (str[*i] && str[*i] != '.')
		(*i)++;
	new = (char *)malloc(sizeof(char) * (*i + 1));
	*i = 0;
	while (str[*i] && str[*i] != '.')
	{
		new[*i] = str[*i];
		(*i)++;
	}
	new[*i] = '\0';
	(*i)++;
	return (new);
}

double	ft_atof(char *str)
{
	int			i;
	int			sign;
	t_decimal	number;
	char		*before_dot;
	int			temp;

	sign = 1;
	before_dot = ft_int(str, &i);
	temp = ft_strlen(str) - 1;
	number.integer = ft_atoi(before_dot);
	number.floatint = 0;
	if (str[i] == '\0')
		return ((double) 0);
	while (ft_isdigit(str[temp]) && temp >= i)
	{
		number.floatint = number.floatint * 0.1 + str[temp] - '0';
		temp--;
	}
	number.floatint = number.floatint * 0.1;
	while (ft_isspace(*str))
		str++;
	ft_set_sign(str, 0, &sign);
	return ((double )(number.integer + ((number.floatint) * sign)));
}
