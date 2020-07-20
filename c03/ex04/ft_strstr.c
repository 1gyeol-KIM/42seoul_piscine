/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <hangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:59:18 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/13 11:28:35 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr_sub(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char *res;

	if (!to_find[0])
		return (str);
	res = ft_strstr_sub(str, to_find);
	if (res == 0)
		return (0);
	else
		return (res);
}

char	*ft_strstr_sub(char *str, char *to_find)
{
	int		i;
	int		j;
	int		chk;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			chk = 0;
			while (to_find[j])
			{
				if (str[i + j] == to_find[j])
					chk++;
				j++;
			}
			if (chk == j)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
