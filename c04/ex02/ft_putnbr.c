/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:46:09 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/15 10:24:00 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(int nb, char res);

void	ft_putnbr(int nb)
{
	char	res;
	char	tmp;

	res = '0';
	tmp = '0';
	if (nb > 0)
		ft_print_char(nb, res);
	else if (nb == 0)
		write(1, &res, 1);
	else
	{
		write(1, "-", 1);
		tmp = ((nb % 10) * -1) + '0';
		ft_print_char(nb / 10 * (-1), res);
		write(1, &tmp, 1);
	}
}

void	ft_print_char(int nb, char res)
{
	if (nb >= 1)
	{
		res = nb % 10 + '0';
		nb /= 10;
		ft_print_char(nb, res);
		write(1, &res, 1);
	}
}
