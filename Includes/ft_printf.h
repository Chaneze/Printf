/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:21:43 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:30:24 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_print
{
	int			index;
	int			size;
	int			neg;
	char		*arg;
	char		c;
}				t_print;

typedef struct	s_params
{
	int			width;
	int			preci;
	int			check;
	char		flag;
	char		type;
}				t_params;

void			get_param(const char *str, t_print *print, t_params *params,
				va_list ap);
void			get_flag(const char *str, t_print *print, t_params *params);
void			get_width(const char *str, t_print *print, t_params *params,
				va_list ap);
void			get_preci(const char *str, t_print *print, t_params *params,
				va_list ap);
void			get_type(const char *str, t_print *print, t_params *params);
void			ft_display(t_print *print, t_params *params, va_list ap);
void			get_arg(t_print *print, t_params *params, va_list ap);
void			ft_character(t_print *print, t_params *params, va_list ap);
void			ft_left_justify_char(t_print *print, int width, char letter);
void			ft_right_justify_char(t_print *print, int width, char letter);
void			ft_string(t_print *print, t_params *params, va_list ap);
void			ft_string_bis(t_print *print, t_params *params, char *str);
void			ft_left_justify_str(t_print *print, int width, int preci,
				char *str);
void			ft_right_justify_str(t_print *print, int width, int preci,
				char *str);
void			ft_address(t_print *print, t_params *params, va_list ap);
void			ft_left_justify_add(t_print *print, int width, char *str);
void			ft_right_justify_add(t_print *print, int width, char *str);
void			ft_int_and_hex(t_print *print, t_params *params, char *str);
void			ft_right_justify_int(t_print *print, int width, char *str);
void			ft_left_justify_int(t_print *print, int width, char *str);

char			*ft_itoa_address_hex(long long n, int preci, char *hex);
char			*ft_itoa_int(int n, int preci, t_print *print);
char			*ft_itoa_unsigned_int(int n, int preci);
char			*ft_itoa_hex(int n, int preci, char *hex);

size_t			ft_strlen(const char *s);
void			ft_putstr(char *s);
int				ft_atoi(const char *str);

#endif
