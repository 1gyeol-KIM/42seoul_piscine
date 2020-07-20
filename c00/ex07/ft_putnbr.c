/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:44:29 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/06 18:51:30 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>

int*	ft_get_p(nb, size)
{
	int num[size];
	int fsize;
	int i;

	i = 0;
	fsize = size;
	while (i < fsize)
	{
		num[i] = nb / pow(10, size - 1);
		nb = nb - num[i] * pow(10, size - 1);
		size --;
		i++;
	}
	return num;
}

void	ft_print_cnum(num, size)
{
	char res[size];
	int i;

	i = 0;
	while (i < size)
	{
		res[i] = num[i] + 48;
		i++;
	}
	write(1, &res, size);
}

void	ft_putnbr(int nb)
{
	int size;

	size = nb / 10 + 1;
	num = ft_get_p(nb, size);
	ft_print(num, size);
}
