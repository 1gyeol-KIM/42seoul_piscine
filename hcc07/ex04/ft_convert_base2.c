/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoi <hchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:59:34 by hchoi             #+#    #+#             */
/*   Updated: 2020/07/18 16:59:26 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		valid_base(char *str);
char	solve_base(char *base, char match);
int		ft_numlen(unsigned int num, int minus, int method);
char	*cal_convert(char *base, unsigned int num, int minus);

int		is_whitespace(char str)
{
	return (str == ' ' || str == '\n' || str == '\t'
			|| str == '\v' || str == '\f' || str == '\r');
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				minus;
	int				method;
	int				solve_result;
	unsigned int	result;

	if (!valid_base(base_from) || !valid_base(base_to))
		return (NULL);
	method = ft_strlen(base_from);
	minus = 1;
	result = 0;
	while (is_whitespace(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr++) == '-')
			minus *= -1;
	}
	while ((solve_result = solve_base(base_from, *nbr)) != -1)
	{
		result *= method;
		result += solve_result;
		nbr++;
	}
	minus = result == 0 ? 1 : minus;
	return (cal_convert(base_to, result, minus > 0 ? 0 : 1));
}
