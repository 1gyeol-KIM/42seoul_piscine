/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <hangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:55:58 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/19 14:25:39 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(int *chk_isval, char *str, char *base);
int		ft_isvalid(char *base);
int		ft_chk_char(char c, char *base);

int		g_nbr_ten;

int		ft_get_length(int g_nbr_ten, int size)
{
	int		len;

	len = 0;
	while (g_nbr_ten)
	{
		len++;
		g_nbr_ten /= size;
	}
	return (len);
}

void	ft_convert_p(int size, int len, char *base_to, char *res)
{
	int		i;

	i = 1;
	while (i <= len)
	{
		res[len - i] = base_to[g_nbr_ten % size];
		g_nbr_ten /= size;
		i++;
	}
}

void	ft_convert_n(int size, int len, char *base_to, char *res)
{
	int		i;

	i = 2;
	while (i + 1 <= len)
	{
		res[len - i] = base_to[g_nbr_ten % size];
		g_nbr_ten /= size;
		i++;
	}
}

char	*ft_convert_int(int size, char *base_to)
{
	int		len;
	int		tmp;
	char	*res;

	len = ft_get_length(g_nbr_ten, size);
	if (g_nbr_ten > 0)
	{
		res = malloc(sizeof(char) * (len + 1));
		ft_convert_p(size, len, base_to, res);
		res[len] = '\0';
	}
	else
	{
		len++;
		res = malloc(sizeof(char) * (len + 1));
		tmp = g_nbr_ten % size * (-1);
		g_nbr_ten = g_nbr_ten / size * (-1);
		ft_convert_n(size, len, base_to, res);
		res[0] = '-';
		res[len - 1] = base_to[tmp];
		res[len] = '\0';
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		size;
	int		*chk_isval;

	chk_isval = &size;
	*chk_isval = 1;
	g_nbr_ten = ft_atoi_base(chk_isval, nbr, base_from);
	if (*chk_isval == 0)
		return (0);
	size = ft_isvalid(base_to);
	if (!size)
		return (0);
	return (ft_convert_int(size, base_to));
}
