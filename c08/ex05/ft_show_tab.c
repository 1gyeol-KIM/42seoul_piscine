/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:23:41 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/20 11:47:33 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int		ft_str_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_str(int len, char *str)
{
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_print_num(int num)
{
	char c;

	if (!num)
		return ;
	c = num % 10 + '0';
	ft_print_num(num / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	int		col_cnt;

	i = 0;
	while (par[i].str)
	{
		col_cnt = ft_str_len(par[i].str);
		ft_print_str(col_cnt, par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_print_num(par[i].size);
		write(1, "\n", 1);
		col_cnt = ft_str_len(par[i].copy);
		ft_print_str(col_cnt, par[i].copy);
		i++;
	}
}
