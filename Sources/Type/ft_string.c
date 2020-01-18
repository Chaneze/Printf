/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:48:37 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:23:41 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_left_justify_str(t_print *print, int width, int preci, char *str)
{
	int i;
	int size;

	i = 0;
	size = (int)ft_strlen(str);
	if (preci >= 0 && preci < size)
	{
		while (i < width && i < preci)
		{
			print->arg[i] = str[i];
			i++;
		}
	}
	else
	{
		while (i < width && i < size)
		{
			print->arg[i] = str[i];
			i++;
		}
	}
	while (i < width)
		print->arg[i++] = print->c;
	print->arg[width] = '\0';
}

void	ft_right_justify_str(t_print *print, int width, int preci, char *str)
{
	int i;
	int size;

	i = 1;
	size = (int)ft_strlen(str);
	print->arg[width] = '\0';
	if (preci >= 0 && preci < size)
	{
		while (i <= width && i <= preci)
		{
			print->arg[width - i] = str[preci - i];
			i++;
		}
	}
	else
	{
		while (i <= width && i <= size)
		{
			print->arg[width - i] = str[size - i];
			i++;
		}
	}
	while (i <= width)
		print->arg[width - i++] = print->c;
}

void	ft_string_bis(t_print *print, t_params *params, char *str)
{
	if ((print->arg = (char *)malloc(sizeof(char) * (params->width + 1))))
	{
		if (params->flag == '-')
			ft_left_justify_str(print, params->width, params->preci, str);
		else
			ft_right_justify_str(print, params->width, params->preci, str);
	}
}

void	ft_string(t_print *print, t_params *params, va_list ap)
{
	char *str;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	if (params->flag == '0')
		print->c = '0';
	if (params->width > (int)ft_strlen(str) \
	|| (params->width > params->preci && params->preci >= 0))
		ft_string_bis(print, params, str);
	else if ((int)ft_strlen(str) > params->preci && params->preci >= 0)
	{
		if ((print->arg = (char *)malloc(sizeof(char) * (params->preci + 1))))
			ft_left_justify_str(print, params->preci, params->preci, str);
	}
	else
	{
		if ((print->arg = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			ft_left_justify_str(print, (int)ft_strlen(str), params->preci, str);
	}
}
