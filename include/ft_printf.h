/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:05:36 by alboumed          #+#    #+#             */
/*   Updated: 2020/09/19 17:05:43 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_flags
{
	int			percent;
	int			minus;
	int			zero;
	int			width;
	int			star1;
	int			dot;
	int			prec;
	int			star2;
	int			type;
	const char	*pos;
	int			len;
}				t_flags;

char			*get_addr(void *addr_src);
void			get_flags(t_flags *flag);
void			print_and_increase(t_flags *flag);
int				ft_printf(const char *s, ...);
void			minus_behavior(t_flags *flag, char *s, intmax_t n);
void			no_minus_behavior(t_flags *flag, char *s, intmax_t n, char c);
int				check_type(char c);
void			type_c(t_flags *flag, va_list param);
void			type_s(t_flags *flag, va_list param);
void			type_p(t_flags *flag, va_list param);
void			type_d(t_flags *flag, va_list param);
void			type_i(t_flags *flag, va_list param);
void			type_u(t_flags *flag, va_list param);
void			type_x(t_flags *flag, va_list param);
void			type_x_upcase(t_flags *flag, va_list param);
void			type_percent(t_flags *flag, va_list param);
void			init_struct(const char *s, t_flags *flag);
void			*ft_bzero(void *s, size_t n);
char			*ft_llitoabase(intmax_t nb, int base);
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
int				ft_toupper(int c);
void			ft_str_toupper(char *s);
size_t			ft_strlen(const char *s);
intmax_t		ft_absolute(intmax_t nb);
int				flag_percent(t_flags *flag);
int				flag_minus(t_flags *flag);
int				flag_zero(t_flags *flag);
int				flag_width(t_flags *flag);
int				flag_star1(t_flags *flag);
int				flag_star2(t_flags *flag);
int				flag_dot(t_flags *flag);
int				flag_prec(t_flags *flag);
void			star1_to_width(t_flags *flag, va_list param);
void			star2_to_prec(t_flags *flag, va_list param);

#endif
