/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:59:01 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:24:36 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv_c_pct(t_format *format, va_list ap)
{
	char	c;

	if (format->conv == '%')
		c = '%';
	else if (format->conv == 'c')
		c = va_arg(ap, int);
	if (format->minus == 1)
	{
		ft_putchar(c, format);
		ft_putwhile(format->width - 1, ' ', format);
	}
	else if (format->zero == 1)
	{
		ft_putwhile(format->width - 1, '0', format);
		ft_putchar(c, format);
	}
	else
	{
		ft_putwhile(format->width - 1, ' ', format);
		ft_putchar(c, format);
	}
}
