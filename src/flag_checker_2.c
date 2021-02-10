/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:56:06 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:58:33 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_star2(t_flags *flag)
{
	flag->star2 = 0;
	if (*flag->pos == '*')
	{
		flag->star2 = 1;
		++flag->pos;
	}
	return (flag->star2);
}

int		flag_dot(t_flags *flag)
{
	flag->dot = 0;
	if (*flag->pos == '.')
	{
		flag->dot = 1;
		++flag->pos;
	}
	return (flag->dot);
}

int		flag_prec(t_flags *flag)
{
	flag->prec = 0;
	if (ft_isdigit(*flag->pos))
	{
		flag->prec = ft_atoi(flag->pos);
		while (ft_isdigit(*flag->pos))
			++flag->pos;
	}
	return (flag->prec);
}

void	star1_to_width(t_flags *flag, va_list param)
{
	if (flag->star1)
		flag->width = va_arg(param, int);
}

void	star2_to_prec(t_flags *flag, va_list param)
{
	if (flag->star2)
		flag->prec = va_arg(param, int);
}
