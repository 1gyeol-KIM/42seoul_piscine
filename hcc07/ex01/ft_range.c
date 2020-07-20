/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:20:29 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/13 17:34:46 by hchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int size;
	int *a;

	if (min >= max)
		return (0);
	i = 0;
	size = max - min;
	if ((a = (int *)malloc(sizeof(int) * size)) == NULL)
		return (0);
	while (i < size)
	{
		a[i] = min + i;
		i++;
	}
	return (a);
}
