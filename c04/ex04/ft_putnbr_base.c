/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:32:29 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/14 19:18:54 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_isvalid(char *base)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (base[i] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		tmp = base[i];
		j = i;
		while (base[j + 1])
		{
			if (tmp == base[j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_print_base(int size, int nbr, char *base)
{
	int		res;

	if (nbr / size == 0)
	{
		res = nbr % size;
		write(1, &base[res], 1);
		return ;
	}
	res = nbr % size;
	ft_print_base(size, nbr / size, base);
	write(1, &base[res], 1);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	tmp;

	size = ft_isvalid(base);
	if (!size)
		return ;
	if (nbr >= 0)
	{
		ft_print_base(size, nbr, base);
		return ;
	}
	write(1, "-", 1);
	tmp = base[(nbr % size) * -1];
	if ((nbr / size) * (-1) > 0)
		ft_print_base(size, (nbr / size) * -1, base);
	write(1, &tmp, 1);
}
