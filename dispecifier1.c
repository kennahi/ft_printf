/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispecifier1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 23:04:46 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:57:25 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			diwidth(t_var *flog)
{
	int		count;

	count = 0;
	while (flog->w > 0)
	{
		ft_putchar(' ');
		flog->w--;
		count++;
	}
	return (count);
}

static	int			diwidthhigher(int i, t_var *flog)
{
	int	count;

	count = 0;
	if (flog->w >= intlen(i))
	{
		if (i < 0)
			flog->w--;
		flog->w = flog->w - flog->p;
		if (flog->flag != 1)
			count += diwidth(flog);
	}
	if (i < 0)
	{
		count += dadditional2(i);
		i *= -1;
	}
	flog->p = flog->p - intlen(i);
	while (flog->p > 0)
	{
		ft_putchar('0');
		count++;
		flog->p--;
	}
	return (count);
}

static	int			diprecisionhigher(int i, t_var *flog)
{
	int	count;

	count = 0;
	if (flog->w >= intlen(i))
	{
		flog->w = flog->w - intlen(i);
		if (flog->flag != 1)
			count += diwidth(flog);
	}
	if (i < 0)
	{
		count += dadditional2(i);
		i = i * -1;
	}
	return (count);
}

static	int			conditions(int i, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->p < 0 && flog->flag == 2)
		count += dizeroprecision(i, flog);
	if (flog->p >= intlen(i))
		count += diwidthhigher(i, flog);
	else if (flog->p < intlen(i))
		count += diprecisionhigher(i, flog);
	return (count);
}

int					dispecifier(const char **str, va_list args, t_var *flog)
{
	int		i;
	int		count;

	count = 0;
	i = va_arg(args, int);
	diconditions(i, flog);
	if (i == 0 && flog->p == 0)
	{
		(*str)++;
		count += diwidth(flog);
		return (count);
	}
	count += conditions(i, flog);
	if (i < 0)
		i *= -1;
	ft_itoa(i);
	if (flog->flag == 1)
		count += diwidth(flog);
	count += intlen(i);
	(*str)++;
	return (count);
}
