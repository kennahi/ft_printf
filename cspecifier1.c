/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspecifier1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:59:14 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:57:34 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			cwidth(t_var *flog)
{
	int		count;

	count = 0;
	flog->w--;
	if (flog->flag != 2)
	{
		while (flog->w > 0)
		{
			ft_putchar(' ');
			flog->w--;
			count++;
		}
	}
	else
	{
		while (flog->w > 0)
		{
			ft_putchar('0');
			flog->w--;
			count++;
		}
	}
	return (count);
}

static	void		cconditions(t_var *flog)
{
	if ((flog->flag == 1) && (flog->w == 0 || flog->w == 1))
		flog->flag = 0;
	if (flog->w < 0)
	{
		flog->flag = 1;
		flog->w *= -1;
	}
}

static	int			conditions(t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w > 1 && flog->flag != 1)
		count += cwidth(flog);
	return (count);
}

int					cspecifier(const char **str, va_list args, t_var *flog)
{
	char	c;
	int		count;

	count = 0;
	if (**str != '%')
		c = va_arg(args, int);
	cconditions(flog);
	count += conditions(flog);
	if (**str == '%')
		ft_putchar('%');
	else
		ft_putchar(c);
	count++;
	if (flog->flag == 1)
		count += cwidth(flog);
	(*str)++;
	return (count);
}
