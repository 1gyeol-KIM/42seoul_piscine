/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:04:13 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/16 14:30:58 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_isvalid(char *base)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		tmp = base[i];
		if (tmp == '+' || tmp == '-' || is_space(tmp))
			return (0);
		j = i;
		while (base[j + 1])
		{
			if (tmp == base[j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_chk_char(char c, char *base)
{
	int		i;

	i = 0;
	if (c == '\t' || c == '\n' || c == '\v')
		return (-3);
	if (c == '\f' || c == '\r' || c == ' ')
		return (-3);
	if (c == '-' || c == '+')
		return (-1);
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-4);
}

int		ft_convert_ten(int i, int size, char *str, char *base)
{
	int		val;
	int		res;

	res = 0;
	val = ft_chk_char(str[i], base);
	while (val >= 0)
	{
		res = res * size + val;
		i++;
		val = ft_chk_char(str[i], base);
	}
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		size;
	int		chk_value;

	i = 0;
	sign = 1;
	size = ft_isvalid(base);
	if (size == 0)
		return (0);
	while (ft_chk_char(str[i], base) == -3)
		i++;
	chk_value = ft_chk_char(str[i], base);
	while (chk_value == -1 && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		chk_value = ft_chk_char(str[i], base);
	}
	return (sign * ft_convert_ten(i, size, str, base));
}
