/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:58:45 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:23:10 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_left_justify_add(t_print *print, int width, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = (int)ft_strlen(str);
	print->arg[i++] = '0';
	print->arg[i++] = 'x';
	if (print->c == '0')
	{
		while (i < width && i < width - size)
			print->arg[i++] = print->c;
		while (j < size)
			print->arg[i++] = str[j++];
	}
	else
	{
		while (j < size)
			print->arg[i++] = str[j++];
		while (i < width)
			print->arg[i++] = print->c;
	}
	print->arg[width] = '\0';
}

void		ft_right_justify_add(t_print *print, int width, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = (int)ft_strlen(str);
	print->arg[width] = '\0';
	while (i < width && i < width - size - 2)
		print->arg[i++] = print->c;
	print->arg[i++] = '0';
	print->arg[i++] = 'x';
	while (j < size)
		print->arg[i++] = str[j++];
	print->arg[width] = '\0';
}

void		ft_address(t_print *print, t_params *params, va_list ap)
{
	char *str;

	if (params->flag == '0' && params->preci < 0)
		print->c = '0';
	if ((str = ft_itoa_address_hex((long long)va_arg(ap, void*),
	params->preci, "0123456789abcdef")))
	{
		if (params->width > (int)ft_strlen(str) + 2)
		{
			if ((print->arg = malloc(sizeof(char) * (params->width + 1))))
			{
				if (params->flag == '-' || print->c == '0')
					ft_left_justify_add(print, params->width, str);
				else
					ft_right_justify_add(print, params->width, str);
			}
		}
		else
		{
			if ((print->arg = malloc(sizeof(char) * (ft_strlen(str) + 2 + 1))))
				ft_left_justify_add(print, (int)ft_strlen(str) + 2, str);
		}
		free(str);
	}
}
