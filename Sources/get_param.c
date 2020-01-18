/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:40:37 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:21:54 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	get_flag(const char *str, t_print *print, t_params *params)
{
	while (str[print->index] == '0' || str[print->index] == '-')
	{
		if (str[print->index] == '0' && params->flag != '-')
			params->flag = '0';
		if (str[print->index] == '-')
			params->flag = '-';
		print->index++;
	}
}

void	get_width(const char *str, t_print *print, t_params *params, va_list ap)
{
	if (str[print->index] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->flag = '-';
			params->width = -params->width;
		}
		print->index++;
	}
	else if (str[print->index] >= '0' && str[print->index] <= '9')
	{
		params->width = ft_atoi(str + print->index);
		while (str[print->index] >= '0' && str[print->index] <= '9')
			print->index++;
	}
}

void	get_preci(const char *str, t_print *print, t_params *params, va_list ap)
{
	if (str[print->index] == '*')
	{
		params->preci = va_arg(ap, int);
		print->index++;
	}
	else if (str[print->index] >= '0' && str[print->index] <= '9')
	{
		params->preci = ft_atoi(str + print->index);
		while (str[print->index] >= '0' && str[print->index] <= '9')
			print->index++;
	}
	else if (str[print->index] == '-')
	{
		print->index++;
		while (str[print->index] >= '0' && str[print->index] <= '9')
			print->index++;
	}
	else
		params->preci = 0;
}

void	get_type(const char *str, t_print *print, t_params *params)
{
	char c;

	c = str[print->index];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'i' \
			|| c == 'x' || c == 'X' || c == '%')
	{
		params->type = str[print->index];
		print->index++;
	}
}
