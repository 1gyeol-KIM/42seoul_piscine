/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <hangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:37:35 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/13 15:27:52 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] > 0)
			return (1);
		if (s1[i] - s2[i] < 0)
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	else if (s2[i] == '\0' && s1[i] != '\0')
		return (1);
	return (0);
}
