/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:55:33 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:58:21 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_percent(t_flags *flag)
{
	flag->percent = 0;
	if (*flag->pos == '%')
	{
		flag->percent = 1;
	}
	return (flag->percent);
}

int	flag_minus(t_flags *flag)
{
	flag->minus = 0;
	while (*flag->pos == '-')
	{
		flag->minus = 1;
		++flag->pos;
	}
	return (flag->minus);
}

int	flag_zero(t_flags *flag)
{
	flag->zero = 0;
	while (*flag->pos == '0')
	{
		++flag->pos;
		flag->zero = 1;
	}
	return (flag->zero);
}

int	flag_width(t_flags *flag)
{
	flag->width = 0;
	if (ft_isdigit(*flag->pos))
	{
		flag->width = ft_atoi(flag->pos);
		while (ft_isdigit(*flag->pos))
			++flag->pos;
	}
	return (flag->width);
}

int	flag_star1(t_flags *flag)
{
	flag->star1 = 0;
	if (*flag->pos == '*')
	{
		flag->star1 = 1;
		++flag->pos;
	}
	return (flag->star1);
}
