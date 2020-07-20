/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <hangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:50:56 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/19 16:16:24 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_total_length(int size, char **strs, char *sep)
{
	int		i;
	int		length;

	i = 0;
	length = ft_length(sep) * (size - 1);
	while (i < size)
	{
		length += ft_length(strs[i]);
		i++;
	}
	length += 1;
	return (length);
}

int		ft_strcat_sub(int index, char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	return (index + i);
}

void	ft_strcat(int size, char **strs, char *sep, char *res)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (i < size)
	{
		index = ft_strcat_sub(index, res, strs[i]);
		if (i != size - 1)
			index = ft_strcat_sub(index, res, sep);
		i++;
	}
	res[index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	char	*res;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = 0;
		return (res);
	}
	length = ft_total_length(size, strs, sep);
	if (!(res = (char *)malloc(sizeof(char) * length)))
		return (0);
	ft_strcat(size, strs, sep, res);
	return (res);
}
