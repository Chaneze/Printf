/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:09:38 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:21:06 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
