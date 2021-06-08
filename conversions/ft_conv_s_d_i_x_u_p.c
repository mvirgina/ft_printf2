/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s_d_i_x_u_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 04:19:35 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:36:34 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_make_str(int *is_neg, t_format *format, va_list ap)
{
	char				*s;
	int					number;
	unsigned long int	unumber;

	s = 0;
	number = 0;
	unumber = 0;
	if (format->conv == 'x' || format->conv == 'X' || format->conv == 'u'
			|| format->conv == 'p')
	{
		if (format->conv == 'p')
			unumber = va_arg(ap, unsigned long int);
		else
			unumber = va_arg(ap, unsigned int);
		s = ft_u_itoa(unumber, format);
		*is_neg = 0;
	}
	if (format->conv == 's')
		s = va_arg(ap, char *);
	if (format->conv == 'd' || format->conv == 'i')
	{
		number = va_arg(ap, int);
		s = ft_itoa(is_neg, number, format);
	}
	return (s);
}

void	ft_handle_s(t_format *format, char *s)
{
	if (format->precision == 0 && format->point != 0 && format->width == 0)
		format->sum += 0;
	if (s == NULL)
		s = "(null)";
	if ((format->precision != 0 && ft_strlen(s) < format->precision)
			|| (format->precision == 0 && format->point == 0))
	{
		format->precision = ft_strlen(s);
		format->width -= format->precision;
	}
	else
		format->width -= format->precision;
	if (format->minus == 0 && format->zero == 0)
		ft_putwhile(format->width, ' ', format);
	else if (format->zero == 1)
		ft_putwhile(format->width, '0', format);
	ft_putstrwhile(format->precision, s, format);
	if (format->minus == 1)
		ft_putwhile(format->width, ' ', format);
}

void	ft_conv_s_d_i_x_u_p(t_format *format, va_list ap)
{
	int		is_neg;
	char	*s;
	int		pref;

	pref = 0;
	if (format->conv == 'p')
		pref = 2;
	s = ft_make_str(&is_neg, format, ap);
	if (format->conv == 's')
		ft_handle_s(format, s);
	if (format->conv == 'd' || format->conv == 'i'
			|| format->conv == 'x' || format->conv == 'X'
			|| format->conv == 'u' || format->conv == 'p')
	{
		if (format->minus == 1)
			ft_minus(is_neg, pref, format, s);
		if (format->zero == 1)
			ft_zero(is_neg, pref, format, s);
		if (format->minus == 0 && format->zero == 0)
			ft_minus_zero(is_neg, pref, format, s);
		free(s);
	}
}
