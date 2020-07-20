/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hangkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:04:12 by hangkim           #+#    #+#             */
/*   Updated: 2020/07/04 18:15:51 by hangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print_line(char a, char b, char c, int width);

void	rush(int width, int length)
{
	if (length > 0)
		ft_print_line('A', 'B', 'C', width);
	while (length > 2)
	{
		ft_print_line('B', ' ', 'B', width);
		length--;
	}
	if (length > 1)
		ft_print_line('A', 'B', 'C', width);
}

void	ft_print_line(char a, char b, char c, int width)
{
	if (width > 0)
		ft_putchar(a);
	while (width > 2)
	{
		ft_putchar(b);
		width--;
	}
	if (width > 1)
		ft_putchar(c);
	if (width >= 1)
		ft_putchar('\n');
}
