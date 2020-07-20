/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trush00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:38:56 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/06 12:47:34 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print_line(char a, char b, char c, int width);

void	rush(int width, int length)
{
	if (length > 0)
		ft_print_line('o', '-', 'o', width);
	while (length > 2)
	{
		ft_print_line('|', ' ', '|', width);
		length--;
	}
	if (length == 2)
		ft_print_line('o', '-', 'o', width);
}

void	ft_print_line(char a, char b, char c, int width)
{
	if (width > 0)
	{
		ft_putchar(a);
		while (width > 2)
		{
			ft_putchar(b);
			width--;
		}
		if (width == 2)
			ft_putchar(c);
		ft_putchar('\n');
	}
}
