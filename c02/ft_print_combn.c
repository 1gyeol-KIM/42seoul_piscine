/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:57:49 by haseo             #+#    #+#             */
/*   Updated: 2020/07/07 20:48:18 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_islast(int check[], int n)
{
	int i;

	i = 10 - n;
	while (i < 10)
	{
		if (check[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(int check[], int n)
{
	int		i;
	char	ch;

	i = 0;
	while (i <= 10)
	{
		if (check[i] == 1)
		{
			ch = i + '0';
			write(1, &ch, 1);
		}
		i++;
	}
	if (!ft_islast(check, n))
	{
		write(1, ", ", 2);
	}
}

void	ft_dfs(int index, int count, int check[], int n)
{
	if (count == n)
	{
		ft_print(check, n);
		return ;
	}
	if (index == 10)
		return ;
	check[index] = 1;
	ft_dfs(index + 1, count + 1, check, n);
	check[index] = 0;
	ft_dfs(index + 1, count, check, n);
}

void	ft_print_combn(int n)
{
	int i;
	int check[10];

	i = 0;
	while (i <= 9)
	{
		check[i] = 0;
		i++;
	}
	ft_dfs(0, 0, check, n);
}
