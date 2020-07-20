/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:04:13 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/16 14:33:09 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_chk_char(char c);

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_chk_char(str[i]) == 1)
		i++;
	while (ft_chk_char(str[i]) == -1 && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (ft_chk_char(str[i]) != 2)
			break ;
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int		ft_chk_char(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	if (c == '-' || c == '+')
		return (-1);
	if ('0' <= c && c <= '9')
		return (2);
	return (0);
}
