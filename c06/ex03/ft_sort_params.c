/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:48:39 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/16 15:12:09 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_compare(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (0);
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	return (0);
}

void	ft_sort(int argc, char *argv[])
{
	int		i;
	int		len;
	int		cmp;
	char	*tmp;

	len = argc;
	i = 1;
	while (i < len)
	{
		cmp = 1;
		while (cmp < len - i)
		{
			if (ft_compare(argv[cmp], argv[cmp + 1]))
			{
				tmp = argv[cmp];
				argv[cmp] = argv[cmp + 1];
				argv[cmp + 1] = tmp;
			}
			cmp++;
		}
		i++;
	}
}

int		ft_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_list(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		write(1, &argv[i][0], ft_length(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ft_sort(argc, argv);
		ft_print_list(argc, argv);
	}
	return (0);
}
