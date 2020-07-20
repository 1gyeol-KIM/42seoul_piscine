/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <hangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:46:50 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/19 23:33:44 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;
	int		*res;
	int		size;

	if (min >= max)
		return (0);
	size = max - min;
	res = (int *)malloc(sizeof(int) * size);
	i = -1;
	if (res == 0)
		return (0);
	while (++i < size)
		res[i] = min++;
	return (res);
}
