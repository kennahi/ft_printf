/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Xspecifier1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:00:33 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:01:16 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			xwidth(t_var *flog)
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

static	int			xwidthhigher(char *s, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w >= ft_strlen(s))
	{
		flog->w = flog->w - flog->p;
		if (flog->flag != 1)
			count += xwidth(flog);
	}
	else
		flog->w = 0;
	flog->p = flog->p - ft_strlen(s);
	while (flog->p > 0)
	{
		ft_putchar('0');
		count++;
		flog->p--;
	}
	return (count);
}

static	int			xprecisionhigher(char *s, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w >= ft_strlen(s))
	{
		flog->w = flog->w - ft_strlen(s);
		if (flog->flag != 1)
			count += xwidth(flog);
	}
	else
		flog->w = 0;
	return (count);
}

static	int			conditions(char *s, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->p < 0 && flog->flag == 2)
	{
		if (flog->w > ft_strlen(s))
			flog->p = flog->w;
	}
	if (flog->p >= ft_strlen(s))
		count += xwidthhigher(s, flog);
	else if (flog->p < ft_strlen(s))
		count += xprecisionhigher(s, flog);
	return (count);
}

int					xspecifier(const char **str, va_list args, t_var *flog)
{
	unsigned int	x;
	char			*s;
	int				count;

	count = 0;
	x = va_arg(args, unsigned int);
	s = xconverter(x, **str);
	xadditional2(s, flog);
	if (flog->p == 0 && x == 0)
	{
		(*str)++;
		count += xwidth(flog);
		return (count);
	}
	count += conditions(s, flog);
	ft_putstr(s);
	if (flog->flag == 1)
		count += xwidth(flog);
	count += ft_strlen(s);
	(*str)++;
	free(s);
	return (count);
}
