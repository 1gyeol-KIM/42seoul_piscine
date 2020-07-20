/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:51:05 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/19 15:57:21 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_chk_sep(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_cnt_charset(char *str, char *charset)
{
	int		chk;
	int		row_cnt;

	chk = 0;
	row_cnt = 0;
	while (*str)
	{
		if (ft_chk_sep(*str, charset))
		{
			if (chk != 0)
			{
				row_cnt++;
				chk = 0;
			}
		}
		else
			chk++;
		str++;
	}
	if (chk > 0)
		row_cnt++;
	return (row_cnt);
}

void	ft_cnt_row_len(int *arr, char *str, char *charset)
{
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	while (*str)
	{
		if (ft_chk_sep(*str, charset))
		{
			if (len != 0)
			{
				arr[idx++] = len;
				len = 0;
			}
		}
		else
			len += 1;
		str++;
	}
	if (len > 0)
		arr[idx++] = len;
	arr[idx] = 0;
}

void	ft_split_str(char *str, char *charset, char **res, int chk)
{
	int		col;
	int		row;

	col = 0;
	row = 0;
	while (*str)
	{
		if (ft_chk_sep(*str, charset))
		{
			if (chk != 0)
			{
				res[row++][col] = '\0';
				col = 0;
				chk = 0;
			}
		}
		else
		{
			chk++;
			res[row][col++] = *str;
		}
		str++;
	}
	if (chk > 0)
		res[row++][col] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		row_cnt;
	int		*arr;
	char	**res;

	row_cnt = ft_cnt_charset(str, charset);
	arr = (int *)malloc(sizeof(int) * (row_cnt + 1));
	ft_cnt_row_len(arr, str, charset);
	res = (char **)malloc(sizeof(char *) * (row_cnt + 1));
	i = 0;
	while (i < row_cnt)
	{
		res[i] = (char *)malloc(sizeof(char) * (arr[i] + 1));
		i++;
	}
	ft_split_str(str, charset, res, 0);
	res[row_cnt] = 0;
	return (res);
}
