/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s_d_i_x_u_p_more.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 04:19:35 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:35:44 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_minus(int is_neg, int pref, t_format *format, char *s)
{
	check_features(is_neg, format);
	if (format->precision == 0 && format->point != 0 && *s == '0')
		ft_putwhile(format->width - pref, ' ', format);
	else if (format->precision >= ft_strlen(s))
	{
		ft_putwhile(format->precision - ft_strlen(s), '0', format);
		ft_putstr(s, format);
		if (format->width - pref >= format->precision)
			ft_putwhile(format->width - pref - format->precision - is_neg,
					' ', format);
	}
	else
	{
		ft_putstr(s, format);
		if (format->width - pref >= ft_strlen(s))
			ft_putwhile(format->width - pref - ft_strlen(s) - is_neg,
					' ', format);
	}
}

void	ft_zero(int is_neg, int pref, t_format *format, char *s)
{
	check_features(is_neg, format);
	if (format->width - pref >= ft_strlen(s))
		ft_putwhile(format->width - pref - ft_strlen(s) - is_neg,
				'0', format);
	ft_putstr(s, format);
}

void	ft_minus_zero(int is_neg, int pref, t_format *format, char *s)
{
	if (format->precision == 0 && format->point != 0 && *s == '0')
	{
		ft_putwhile(format->width - pref, ' ', format);
		if (format->conv == 'p')
			ft_putstr("0x", format);
	}
	else if (format->precision >= ft_strlen(s))
	{
		if (format->width - pref >= format->precision)
			ft_putwhile(format->width - pref - format->precision - is_neg,
					' ', format);
		check_features(is_neg, format);
		ft_putwhile(format->precision - ft_strlen(s), '0', format);
		ft_putstr(s, format);
	}
	else
	{
		if (format->width - pref >= ft_strlen(s))
			ft_putwhile(format->width - pref - ft_strlen(s) - is_neg,
					' ', format);
		check_features(is_neg, format);
		ft_putstr(s, format);
	}
}

void	check_features(int is_neg, t_format *format)
{
	if (is_neg == 1)
		ft_putchar('-', format);
	if (format->conv == 'p')
		ft_putstr("0x", format);
}
