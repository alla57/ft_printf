/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_behaviors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:57:09 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:59:04 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_behavior(t_flags *flag, char *s, intmax_t n)
{
	if (!n && flag->dot && !flag->prec)
		s = "";
	while (flag->prec > (int)ft_strlen(s))
	{
		write(1, "0", 1);
		--flag->width;
		--flag->prec;
		++flag->len;
	}
	if (flag->type == 2)
		write(1, "0x", 2);
	while (*s)
	{
		write(1, s++, 1);
		--flag->width;
		++flag->len;
	}
	while (flag->width-- > 0 && ++flag->len)
		write(1, " ", 1);
}

void	no_minus_behavior(t_flags *flag, char *s, intmax_t n, char c)
{
	if (!n && flag->dot && !flag->prec)
		s = "";
	if (flag->type == 2 && flag->zero)
		write(1, "0x", 2);
	while (flag->width > (int)ft_strlen(s) && flag->width > flag->prec)
	{
		write(1, &c, 1);
		--flag->width;
		++flag->len;
	}
	if (n < 0 && !(flag->zero && flag->dot == 0) && ++flag->len)
		write(1, "-", 1);
	if (flag->type == 2 && !flag->zero)
		write(1, "0x", 2);
	while (flag->prec-- > (int)ft_strlen(s) && ++flag->len)
		write(1, "0", 1);
	while (*s && ++flag->len)
		write(1, s++, 1);
}
