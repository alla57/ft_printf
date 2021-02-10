/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:57:23 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:59:13 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(char c)
{
	char	*type;
	int		i;

	i = 0;
	type = "cspdiuxX%";
	while (c != type[i] && type[i])
		++i;
	if (c == type[i] && type[i])
		return (i);
	return (-1);
}

void	type_c(t_flags *flag, va_list param)
{
	char	c;
	char	d;

	star1_to_width(flag, param);
	c = va_arg(param, int);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	d = (flag->zero == 1 ? '0' : ' ');
	if (flag->minus)
	{
		write(1, &c, 1);
		while (++flag->len && --flag->width > 0)
			write(1, " ", 1);
	}
	else
	{
		while (++flag->len && --flag->width > 0)
			write(1, &d, 1);
		write(1, &c, 1);
	}
}

void	type_s(t_flags *flag, va_list param)
{
	char	*s;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	s = va_arg(param, char*);
	flag->prec < 0 ? flag->dot = 0 : 1;
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	if (!s)
		s = "(null)";
	while (!flag->minus && (flag->width > (int)ft_strlen(s) ||
	(flag->dot && flag->width > flag->prec)))
	{
		write(1, flag->zero ? "0" : " ", 1);
		--flag->width;
		++flag->len;
	}
	while (*s && (flag->dot == 0 || flag->prec > 0) && ++flag->len)
	{
		write(1, s++, 1);
		--flag->width;
		--flag->prec;
	}
	while (flag->minus && flag->width-- > 0 && ++flag->len)
		write(1, " ", 1);
}

void	type_p(t_flags *flag, va_list param)
{
	char	c;
	char	*s;
	void	*addr;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	addr = va_arg(param, void*);
	s = get_addr(addr);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (flag->zero)
		c = '0';
	if (flag->dot || !flag->zero)
		c = ' ';
	if ((intmax_t*)addr == 0 && flag->dot && !flag->prec)
		s = "";
	flag->len += 2;
	flag->width -= 2;
	if (flag->minus)
		minus_behavior(flag, s, 1);
	else
		no_minus_behavior(flag, s, 1, c);
}

void	type_d(t_flags *flag, va_list param)
{
	char	*s;
	char	c;
	int		n;

	star1_to_width(flag, param);
	star2_to_prec(flag, param);
	n = va_arg(param, int);
	s = ft_llitoabase(n, 10);
	flag->width < 0 ? flag->minus = 1 : 1;
	flag->width < 0 ? flag->width = -flag->width : 1;
	flag->prec < 0 ? flag->dot = 0 : 1;
	if (n < 0)
		--flag->width;
	if (n < 0 && (flag->minus || (flag->zero && flag->dot == 0)) && ++flag->len)
		write(1, "-", 1);
	if (flag->zero)
		c = '0';
	if (flag->dot || flag->zero == 0)
		c = ' ';
	if (flag->minus)
		minus_behavior(flag, s, n);
	else
		no_minus_behavior(flag, s, n, c);
}
