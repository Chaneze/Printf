/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:56:23 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:30:27 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

static int	ft_length_nb_itoa_unsigned(unsigned n, int preci)
{
	int size;

	if (n == 0 && preci == 0)
		return (0);
	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_unsigned_int(int n, int preci)
{
	unsigned int	n_un;
	int				size;
	int				length;
	char			*new;

	if (n < 0)
		n_un = 4294967295 + n + 1;
	else
		n_un = n;
	size = ft_length_nb_itoa_unsigned(n_un, preci);
	length = (preci > size) ? preci : size;
	if ((new = (char *)malloc(sizeof(char) * length + 1)) == NULL)
		return (NULL);
	new[length--] = '\0';
	while (length >= 0 && size >= 0)
	{
		new[length] = (n_un % 10) + '0';
		n_un = n_un / 10;
		length--;
	}
	while (length >= 0)
		new[length--] = '0';
	return (new);
}
