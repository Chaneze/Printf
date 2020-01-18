/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:14:50 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 17:32:23 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

static int	ft_length_nb_itoa_hex(long n, int preci)
{
	int size;

	if (n == 0 && preci == 0)
		return (0);
	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char		*ft_itoa_hex(int n, int preci, char *hex)
{
	long	n_long;
	int		size;
	int		length;
	char	*new;

	if (n < 0)
		n_long = 4294967295 + n + 1;
	else
		n_long = n;
	size = ft_length_nb_itoa_hex(n_long, preci);
	length = (preci > size) ? preci : size;
	if ((new = (char *)malloc(sizeof(char) * length + 1)) == NULL)
		return (NULL);
	new[length--] = '\0';
	while (length >= 0 && size >= 0)
	{
		new[length--] = hex[n_long % 16];
		n_long = n_long / 16;
		size--;
	}
	while (length >= 0)
		new[length--] = '0';
	return (new);
}
