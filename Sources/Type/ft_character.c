/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:05:01 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 17:08:39 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

void	ft_left_justify_char(t_print *print, int width, char letter)
{
	int i;

	i = 0;
	if (letter != '\0')
		print->arg[i++] = letter;
	else
	{
		print->size = print->size + 1;
		width--;
	}
	while (i < width)
	{
		print->arg[i] = print->c;
		i++;
	}
	print->arg[i] = '\0';
}

void	ft_right_justify_char(t_print *print, int width, char letter)
{
	int i;

	i = 0;
	while (i < width - 1)
	{
		print->arg[i] = print->c;
		i++;
	}
	if (letter != '\0')
		print->arg[i++] = letter;
	else
		print->size = print->size + 1;
	print->arg[i] = '\0';
}

void	ft_character(t_print *print, t_params *params, va_list ap)
{
	char letter;

	letter = '%';
	if (params->flag == '0')
		print->c = '0';
	if (params->type == 'c')
		letter = va_arg(ap, int);
	if (params->width > 0)
	{
		if ((print->arg = (char *)malloc(sizeof(char) * (params->width + 1))))
		{
			if (params->flag == '-')
				ft_left_justify_char(print, params->width, letter);
			else
				ft_right_justify_char(print, params->width, letter);
		}
	}
	else
	{
		if ((print->arg = (char *)malloc(sizeof(char) * (2))))
			ft_left_justify_char(print, 1, letter);
	}
}
