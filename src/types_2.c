/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:57:35 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:59:27 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_i(t_flags *flag, va_list param)
{
	type_d(flag, param);
}

void	type_u(t_flags *flag, va_list param)
{
	char			*s;
	char			c;
	unsigned int	n;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	n = va_arg(param, unsigned int);
	s = ft_llitoabase(n, 10);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (flag->zero)
		c = '0';
	if (flag->dot || flag->zero == 0)
		c = ' ';
	if (flag->minus)
		minus_behavior(flag, s, n);
	else
		no_minus_behavior(flag, s, n, c);
}

void	type_x(t_flags *flag, va_list param)
{
	char			*s;
	char			c;
	unsigned int	n;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	n = va_arg(param, unsigned int);
	s = ft_llitoabase(n, 16);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (flag->zero)
		c = '0';
	if (flag->dot || flag->zero == 0)
		c = ' ';
	if (flag->minus)
		minus_behavior(flag, s, n);
	else
		no_minus_behavior(flag, s, n, c);
}

void	type_x_upcase(t_flags *flag, va_list param)
{
	char			*s;
	char			c;
	unsigned int	n;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	n = va_arg(param, unsigned int);
	s = ft_llitoabase(n, 16);
	ft_str_toupper(s);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (flag->zero)
		c = '0';
	if (flag->dot || flag->zero == 0)
		c = ' ';
	if (flag->minus)
		minus_behavior(flag, s, n);
	else
		no_minus_behavior(flag, s, n, c);
}

void	type_percent(t_flags *flag, va_list param)
{
	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (flag->minus)
	{
		write(1, "%", 1);
		while (++flag->len && --flag->width > 0)
			write(1, " ", 1);
	}
	else
	{
		while (++flag->len && --flag->width > 0)
			write(1, (flag->zero ? "0" : " "), 1);
		write(1, "%", 1);
	}
}
