/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:24:37 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/14 17:13:09 by hchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_strcat(char *dest, char *src, int index)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	return (index + i);
}

void	ft_strcatcat(char **strs, char *sep, int size, char *result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = ft_strcat(result, strs[i], j);
		if (i < size - 1)
			j = ft_strcat(result, sep, j);
		i++;
	}
	result[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		total_length;

	i = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_length = ft_strlen(sep) * (size - 1);
	while (strs[i])
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	if (!(result = (char *)malloc(sizeof(char) * total_length + 1)))
		return (0);
	ft_strcatcat(strs, sep, size, result);
	return (result);
}
