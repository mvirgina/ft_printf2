/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:05:28 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 18:55:21 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fill_format(t_format *format)
{
	format->minus = 0;
	format->zero = 0;
	format->width = 0;
	format->point = 0;
	format->precision = 0;
	format->conv = 0;
	format->basis = 0;
}

int		parse_format(const char *s, t_format *format, va_list ap)
{
	int i;

	i = 0;
	while ((s[i] >= 48 && s[i] <= 57) || s[i] == '-' || s[i] == '*'
			|| s[i] == '.')
	{
		if (s[i] == '-')
		{
			format->minus = 1;
			format->zero = 0;
		}
		if (s[i] == '*')
			parse_star(format, ap);
		if (s[i] == '.')
		{
			format->point += 1;
			format->precision = 0;
		}
		if (s[i] >= 48 && s[i] <= 57)
			parse_number(s[i], format);
		i++;
	}
	format->conv = s[i];
	parse_conversion(format, ap);
	return (i);
}

void	parse_number(const char s, t_format *format)
{
	if (s == '0' && format->width == 0 && format->precision == 0
			&& format->minus == 0 && format->point == 0)
		format->zero = 1;
	if (format->point == 0)
		format->width = format->width * 10 + (s - 48);
	if (format->point != 0)
	{
		format->precision = format->precision * 10 + (s - 48);
	}
}

void	parse_star(t_format *format, va_list ap)
{
	if (format->point == 0)
	{
		format->width = va_arg(ap, int);
		if (format->width < 0)
		{
			format->minus = 1;
			format->zero = 0;
			format->width *= -1;
		}
	}
	if (format->point != 0)
	{
		format->precision = va_arg(ap, int);
		if (format->precision < 0)
		{
			format->point = 0;
			format->precision = 0;
		}
	}
}

void	parse_conversion(t_format *format, va_list ap)
{
	if (format->point != 0 && format->precision >= 0 && format->conv != 'c'
			&& format->conv != '%')
		format->zero = 0;
	if (format->conv == 'u' || format->conv == 'd' || format->conv == 'i')
		format->basis = "0123456789";
	if (format->conv == 'x' || format->conv == 'p')
		format->basis = "0123456789abcdef";
	if (format->conv == 'X')
		format->basis = "0123456789ABCDEF";
	if (format->conv == 's' || format->conv == 'd' || format->conv == 'i'
			|| format->conv == 'x' || format->conv == 'X' || format->conv == 'u'
			|| format->conv == 'p')
		ft_conv_s_d_i_x_u_p(format, ap);
	else if (format->conv == 'c' || format->conv == '%')
		ft_conv_c_pct(format, ap);
	else if (format->conv == 0)
		ft_putstr("", format);
	else
		ft_handle_s(format, &format->conv);
}
