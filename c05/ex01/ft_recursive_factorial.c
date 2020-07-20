/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:52:57 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/15 17:19:27 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (res);
	if (nb > 0)
		res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
