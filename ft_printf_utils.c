/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:49:38 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 19:58:42 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

static char	*checker(const char *str)
{
	while (*str == '\r' || *str == '\n' || *str == '\f' ||
			*str == '\v' || *str == '\t' || *str == ' ')
		str++;
	return ((char *)str);
}

int			ft_atoi(const char *str)
{
	int sign;
	int value;
	int test;

	sign = 1;
	value = 0;
	str = checker(str);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		test = value;
		value = value * 10 + sign * (*str - '0');
		if (sign == -1 && test < value)
			return (0);
		else if (sign == 1 && test > value)
			return (-1);
		str++;
	}
	return (value);
}
