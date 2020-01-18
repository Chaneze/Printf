/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_and_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:58:54 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:26:17 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void		ft_left_justify_int(t_print *print, int width, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = (int)ft_strlen(str);
	if (print->neg == 1)
		print->arg[i++] = '-';
	if (print->c == '0')
	{
		while (i < width - size)
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

void		ft_right_justify_int(t_print *print, int width, char *str)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = (int)ft_strlen(str);
	print->arg[width] = '\0';
	while (i < width - size - print->neg)
		print->arg[i++] = print->c;
	if (print->neg == 1)
		print->arg[i++] = '-';
	while (j < size)
		print->arg[i++] = str[j++];
	print->arg[width] = '\0';
}

void		ft_int_and_hex(t_print *print, t_params *params, char *str)
{
	int size;

	if (params->flag == '0' && params->preci < 0)
		print->c = '0';
	if (str)
	{
		if (params->width > (int)ft_strlen(str) + print->neg)
		{
			if ((print->arg = malloc(sizeof(char) * (params->width + 1))))
			{
				if (params->flag == '-' || print->c == '0')
					ft_left_justify_int(print, params->width, str);
				else
					ft_right_justify_int(print, params->width, str);
			}
		}
		else
		{
			size = (int)ft_strlen(str) + print->neg;
			if ((print->arg = (char *)malloc(sizeof(char) * (size + 1))))
				ft_left_justify_int(print, size, str);
		}
		free(str);
	}
}
