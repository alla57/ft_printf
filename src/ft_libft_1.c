/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:56:24 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:58:40 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

void		ft_str_toupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

intmax_t	ft_absolute(intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}
