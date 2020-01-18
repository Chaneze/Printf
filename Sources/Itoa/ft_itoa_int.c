/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:56:23 by charoua           #+#    #+#             */
/*   Updated: 2020/01/18 15:22:51 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_printf.h"

static int	ft_length_nb_itoa(long n, t_print *print, int preci)
{
	int size;

	if (n == 0 && preci == 0)
		return (0);
	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		n = -n;
		print->neg = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_int(int n, int preci, t_print *print)
{
	long	n_long;
	int		size;
	int		length;
	char	*new;

	n_long = n;
	size = ft_length_nb_itoa(n_long, print, preci);
	if (n_long < 0)
		n_long = -n_long;
	length = (preci > size) ? preci : size;
	if ((new = (char *)malloc(sizeof(char) * length + 1)) == NULL)
		return (NULL);
	new[length--] = '\0';
	while (length >= 0 && size >= 0)
	{
		new[length] = (n_long % 10) + '0';
		n_long = n_long / 10;
		length--;
	}
	while (length >= 0)
		new[length--] = '0';
	return (new);
}
