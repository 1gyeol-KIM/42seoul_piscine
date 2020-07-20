/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:59:50 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/08 13:40:09 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (n)
	{
		if (src[i] == '\0' || check == 1)
		{
			dest[i] = '\0';
			check = 1;
		}
		else
			dest[i] = src[i];
		n--;
		i++;
	}
	return (dest);
}
