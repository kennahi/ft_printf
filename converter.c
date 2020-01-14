/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:07:51 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 19:47:46 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*xreverse(char *hex)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(hex) - 1;
	i = 0;
	while (i < len)
	{
		temp = hex[i];
		hex[i++] = hex[len];
		hex[len--] = temp;
	}
	return (hex);
}

char			*xconverter(unsigned int n, char x)
{
	char	*hex;
	int		temp;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	hex = (char *)malloc(sizeof(char) * 20);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex[i++] = temp + 48;
		else
			hex[i++] = (x - 33) + temp;
		n /= 16;
	}
	hex[i] = '\0';
	hex = xreverse(hex);
	return (hex);
}

char			*pconverter(unsigned long int n)
{
	char	*hex;
	int		temp;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	hex = (char *)malloc(sizeof(char) * 20);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex[i++] = temp + 48;
		else
			hex[i++] = temp + 87;
		n /= 16;
	}
	hex[i] = '\0';
	hex = xreverse(hex);
	return (hex);
}
