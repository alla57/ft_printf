/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:56:55 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:58:57 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(const char *s, t_flags *flag)
{
	flag->pos = s;
	flag->percent = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->star1 = 0;
	flag->dot = 0;
	flag->prec = 0;
	flag->star2 = 0;
	flag->type = -1;
	flag->len = 0;
}

char	*get_addr(void *addr_src)
{
	intmax_t	addr;

	addr = (uintmax_t)addr_src;
	return (ft_llitoabase(addr, 16));
}

void	get_flags(t_flags *flag)
{
	flag_percent(flag);
	++flag->pos;
	flag_minus(flag);
	flag_zero(flag);
	if (!flag->minus)
		flag_minus(flag);
	while (*flag->pos == '-' || *flag->pos == '0')
		++flag->pos;
	flag_width(flag);
	flag_star1(flag);
	flag_dot(flag);
	flag_prec(flag);
	flag_star2(flag);
}

void	print_and_increase(t_flags *flag)
{
	while (flag_percent(flag) == 0 && *flag->pos)
	{
		write(1, flag->pos, 1);
		++flag->len;
		++flag->pos;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list		param;
	t_flags		flag_dest;
	t_flags		*flag;
	static void	(*ft_type[])(t_flags*, va_list) = {type_c, type_s, type_p,
	type_d, type_i, type_u, type_x, type_x_upcase, type_percent};

	flag = &flag_dest;
	va_start(param, s);
	init_struct(s, flag);
	while (*flag->pos)
	{
		print_and_increase(flag);
		if (!*flag->pos)
			return (flag->len);
		get_flags(flag);
		if (!*flag->pos)
			return (flag->len);
		if ((flag->type = check_type(*flag->pos)) == -1)
			return (-1);
		(*ft_type[flag->type])(flag, param);
		flag->type = -1;
		++flag->pos;
	}
	va_end(param);
	return (flag->len);
}
