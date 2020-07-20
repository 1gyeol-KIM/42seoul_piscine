/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:38:23 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/13 18:27:34 by hchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*a;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = 0;
	size = max - min;
	if ((a = (int *)malloc(size * sizeof(int))) == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = a;
	while (i < size)
	{
		a[i] = min + i;
		i++;
	}
	return (size);
}
