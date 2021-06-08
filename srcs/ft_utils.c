/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:08 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:39:06 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char s, t_format *format)
{
	write(1, &s, 1);
	format->sum += 1;
}

void	ft_putstr(char *s, t_format *format)
{
	while (*s)
	{
		ft_putchar(*s, format);
		s++;
	}
}

void	ft_putstrwhile(int qty, char *s, t_format *format)
{
	while (*s && qty > 0)
	{
		ft_putchar(*s, format);
		qty--;
		s++;
	}
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putwhile(int qty, char s, t_format *format)
{
	while (qty > 0)
	{
		ft_putchar(s, format);
		qty--;
	}
}
