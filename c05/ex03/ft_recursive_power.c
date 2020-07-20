/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:32:33 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/15 17:42:54 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int		res;

	res = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	res *= ft_recursive_power(nb, power - 1);
	return (res);
}
