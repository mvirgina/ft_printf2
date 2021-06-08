/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <mvirgina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:52:20 by mvirgina          #+#    #+#             */
/*   Updated: 2021/01/17 15:54:23 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_format
{
	int		minus;
	int		zero;
	int		width;
	int		point;
	int		precision;
	char	conv;
	int		sum;
	char	*basis;
}				t_format;

void			fill_format(t_format *format);
void			parse_number(const char s, t_format *format);
void			parse_star(t_format *format, va_list ap);
void			parse_conversion(t_format *format, va_list ap);
void			ft_putchar(char s, t_format *format);
void			ft_putstr(char *s, t_format *format);
void			ft_putstrwhile(int qty, char *s, t_format *format);
void			ft_putwhile(int qty, char s, t_format *format);
void			ft_conv_c_pct(t_format *format, va_list ap);
void			ft_handle_s(t_format *format, char *s);
void			ft_conv_s_d_i_x_u_p(t_format *format, va_list ap);
void			ft_minus(int is_neg, int pref, t_format *format, char *s);
void			ft_zero(int is_neg, int pref, t_format *format, char *s);
void			ft_minus_zero(int is_neg, int pref, t_format *format, char *s);
void			check_features(int is_neg, t_format *format);

int				ft_printf(const char *s, ...);
int				parse_format(const char *s, t_format *format, va_list ap);
int				ft_strlen(char *s);
int				ft_numlen(int *is_neg, long int number);
int				ft_u_numlen(unsigned long int dec, t_format *format);

char			*ft_itoa(int *is_neg, long int number, t_format *format);
char			*ft_u_itoa(unsigned long int number, t_format *format);
char			*ft_make_str(int *is_neg, t_format *format, va_list ap);

#endif
