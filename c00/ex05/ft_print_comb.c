/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:29:18 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/06 14:08:14 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int		i;
	char	c[5];

	i = 0;
	c[0] = '0';
	c[3] = ',';
	c[4] = ' ';
	while (c[0] <= '7')
	{
		c[1] = c[0] + 1;
		while (c[1] <= '8')
		{
			c[2] = c[1] + 1;
			while (c[2] <= '9')
			{
				write(1, &c[0], 3);
				if (!(c[0] == '7' && c[1] == '8' && c[2] == '9'))
					write(1, &c[3], 2);
				c[2] += 1;
			}
			c[1] += 1;
		}
		c[0] += 1;
	}
}
