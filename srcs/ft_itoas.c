/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:08 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:42:26 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_numlen(int *is_neg, long int number)
{
	int i;

	i = 1;
	*is_neg = (number < 0) ? 1 : 0;
	if (number < 0)
		number *= -1;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int *is_neg, long int number, t_format *format)
{
	char	*result;
	int		length;

	length = ft_numlen(is_neg, number);
	if (number < 0)
		number *= -1;
	if (!(result = malloc((length + 1) * sizeof(*result))))
		return (NULL);
	result[length] = '\0';
	while (length-- != 0)
	{
		result[length] = format->basis[number % 10];
		number /= 10;
	}
	return (result);
}

int		ft_u_numlen(unsigned long int dec, t_format *format)
{
	int i;

	i = 1;
	if (format->conv == 'x' || format->conv == 'X' || format->conv == 'p')
	{
		while (dec >= 16)
		{
			dec /= 16;
			i++;
		}
	}
	if (format->conv == 'u')
	{
		while (dec >= 10)
		{
			dec /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_u_itoa(unsigned long int number, t_format *format)
{
	char	*result;
	int		length;

	length = ft_u_numlen(number, format);
	if (!(result = malloc((length + 1) * sizeof(*result))))
		return (NULL);
	result[length] = '\0';
	while (length-- != 0)
	{
		if (format->conv == 'x' || format->conv == 'X' || format->conv == 'p')
		{
			result[length] = format->basis[number % 16];
			number /= 16;
		}
		if (format->conv == 'u')
		{
			result[length] = format->basis[number % 10];
			number /= 10;
		}
	}
	return (result);
}
