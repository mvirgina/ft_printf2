/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:46:44 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:47:00 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_format	format;
	va_list		ap;
	int			i;

	format.sum = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		fill_format(&format);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i])
				i += parse_format(&s[i], &format, ap);
		}
		else
			ft_putchar(s[i], &format);
		if (s[i])
			i++;
	}
	va_end(ap);
	return (format.sum);
}
