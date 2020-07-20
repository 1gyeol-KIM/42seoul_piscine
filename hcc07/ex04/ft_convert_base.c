/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <hchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:25:46 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/16 17:00:01 by hchoi            ###   ########.fr       */
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

int		valid_base(char *str)
{
	char	*cur;
	int		i;
	int		j;

	cur = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*cur)
	{
		if (*cur == ' ' || *cur == '+' || *cur == '-' || *cur == '\n'
				|| *cur == '\t' || *cur == '\r' || *cur == '\v' || *cur == '\f')
			return (0);
		cur++;
	}
	i = 0;
	while (i < cur - str)
	{
		j = i + 1;
		while (j < cur - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

char	solve_base(char *base, char match)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == match)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_numlen(unsigned int num, int minus, int method)
{
	unsigned int len;

	len = minus;
	while (1)
	{
		len++;
		if (num / method == 0)
			break ;
		num /= method;
	}
	return (len);
}

char	*cal_convert(char *base, unsigned int num, int minus)
{
	int		len;
	int		method;
	int		i;
	char	*str;

	method = ft_strlen(base);
	len = ft_numlen(num, minus, method);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (minus)
		*str = '-';
	i = minus ? 1 : 0;
	while (i < len)
	{
		str[len - i - !minus] = base[num % method];
		num /= method;
		i++;
	}
	str[len] = '\0';
	return (str);
}
