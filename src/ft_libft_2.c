/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:56:37 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 15:58:49 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_llitoabase(intmax_t nb, int base)
{
	static char	s[22];
	static char	str[] = "0123456789abcdef";
	int			i;
	intmax_t	temp;

	nb = ft_absolute(nb);
	ft_bzero(s, 22);
	i = 0;
	if (nb <= 0 && (i = 1))
		nb = -nb;
	temp = nb;
	while (nb != 0 && ++i)
		nb /= base;
	nb = temp;
	s[i--] = '\0';
	while (i >= 0)
	{
		s[i--] = str[nb % base];
		nb /= base;
	}
	if (s[0] == '0' && s[1] != '\0')
		s[0] = '-';
	return (s);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
