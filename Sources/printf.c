/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:14:54 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 17:34:40 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	get_arg(t_print *print, t_params *params, va_list ap)
{
	if (params->type == 'c' || params->type == '%')
		ft_character(print, params, ap);
	else if (params->type == 's')
		ft_string(print, params, ap);
	else if (params->type == 'p')
		ft_address(print, params, ap);
	else if (params->type == 'd' || params->type == 'i')
		ft_int_and_hex(print, params, ft_itoa_int(va_arg(ap, int),
		params->preci, print));
	else if (params->type == 'u')
		ft_int_and_hex(print, params, ft_itoa_unsigned_int(va_arg(ap, int),
		params->preci));
	else if (params->type == 'X')
		ft_int_and_hex(print, params, ft_itoa_hex(va_arg(ap, int),
		params->preci, "0123456789ABCDEF"));
	else if (params->type == 'x')
		ft_int_and_hex(print, params, ft_itoa_hex(va_arg(ap, int),
		params->preci, "0123456789abcdef"));
}

void	ft_display(t_print *print, t_params *params, va_list ap)
{
	print->arg = NULL;
	print->neg = 0;
	get_arg(print, params, ap);
	if (print->arg)
	{
		ft_putstr(print->arg);
		print->size = print->size + (int)ft_strlen(print->arg);
		free(print->arg);
	}
}

void	get_param(const char *str, t_print *print, t_params *params, va_list ap)
{
	print->index++;
	if ((params = (t_params*)malloc(sizeof(t_params))))
	{
		params->flag = '\0';
		params->width = -2;
		params->preci = -2;
		params->type = '\0';
		get_flag(str, print, params);
		get_width(str, print, params, ap);
		if (str[print->index] == '.')
		{
			print->index++;
			get_preci(str, print, params, ap);
		}
		get_type(str, print, params);
		if (params->type != '\0')
			ft_display(print, params, ap);
		free(params);
	}
}

int		ft_printf(const char *str, ...)
{
	t_print		print;
	t_params	*params;
	va_list		ap;

	print.index = 0;
	print.size = 0;
	print.c = ' ';
	va_start(ap, str);
	params = NULL;
	while (str[print.index] != '\0')
	{
		if (str[print.index] == '%')
			get_param(str, &print, params, ap);
		else
		{
			write(1, &str[print.index], 1);
			print.size++;
			print.index++;
		}
	}
	va_end(ap);
	return (print.size);
}
