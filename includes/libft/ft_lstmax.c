/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:47:43 by tpetros           #+#    #+#             */
/*   Updated: 2023/04/04 15:47:47 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmax(t_list **lst, int size)
{
	int		min;
	t_list	*temp;
	int		i;

	temp = *lst;
	i = 0;
	min = temp->content;
	while (i < size)
	{
		if (min < temp->content)
			min = temp->content;
		temp = temp->next;
		i++;
	}
	return (min);
}
