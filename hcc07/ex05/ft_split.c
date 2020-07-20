/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:05:01 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/15 15:13:40 by hchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_str_split(char **result, char *str, char *charset, int num)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			if (num != 0)
			{
				result[row++][col] = '\0';
				col = 0;
				num = 0;
			}
		}
		else
		{
			num++;
			result[row][col++] = *str;
		}
		str++;
	}
	if (num > 0)
		result[row++][col] = '\0';
}

void	ft_count_each_length(int *arr, char *str, char *charset)
{
	int arr_index;
	int num;

	num = 0;
	arr_index = 0;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			if (num != 0)
			{
				arr[arr_index++] = num;
				num = 0;
			}
		}
		else
			num += 1;
		str++;
	}
	if (num > 0)
		arr[arr_index++] = num;
	arr[arr_index] = 0;
}

int		ft_count_charset(char *str, char *charset)
{
	int count;
	int string_num;

	count = 0;
	string_num = 0;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			if (count != 0)
			{
				string_num++;
				count = 0;
			}
		}
		else
			count++;
		str++;
	}
	if (count > 0)
		string_num++;
	return (string_num);
}

char	**ft_split(char *str, char *charset)
{
	int		string_num;
	int		*arr;
	char	**result;
	int		i;

	i = 0;
	string_num = ft_count_charset(str, charset);
	arr = (int *)malloc(sizeof(int) * (string_num + 1));
	ft_count_each_length(arr, str, charset);
	result = (char **)malloc(sizeof(char*) * (string_num + 1));
	while (i < string_num)
	{
		result[i] = (char*)malloc(sizeof(char) * (arr[i] + 1));
		i++;
	}
	i = 0;
	ft_str_split(result, str, charset, i);
	result[string_num] = NULL;
	return (result);
}
