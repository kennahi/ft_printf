/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uspecifier1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:29:01 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/07 17:20:39 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			uwidth(t_var *flog)
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

static	int			uwidthhigher(int i, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w >= unintlen(i))
	{
		flog->w = flog->w - flog->p;
		if (flog->flag != 1)
			count += uwidth(flog);
	}
	flog->p = flog->p - unintlen(i);
	while (flog->p > 0)
	{
		ft_putchar('0');
		count++;
		flog->p--;
	}
	return (count);
}

static	int			uprecisionhigher(int i, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w >= unintlen(i))
	{
		flog->w = flog->w - unintlen(i);
		if (flog->flag != 1)
			count += uwidth(flog);
	}
	return (count);
}

static	int			conditions(int i, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->p < 0 && flog->flag == 2)
	{
		if (flog->w > unintlen(i))
			flog->p = flog->w;
	}
	if (flog->p >= unintlen(i))
		count += uwidthhigher(i, flog);
	else if (flog->p < unintlen(i))
		count += uprecisionhigher(i, flog);
	return (count);
}

int					uspecifier(const char **str, va_list args, t_var *flog)
{
	unsigned int	i;
	int				count;

	count = 0;
	i = va_arg(args, unsigned int);
	uconditions(i, flog);
	if (i == 0 && flog->p == 0)
	{
		(*str)++;
		count += uwidth(flog);
		return (count);
	}
	count += conditions(i, flog);
	ft_itoaa(i);
	if (flog->flag == 1)
		count += uwidth(flog);
	count += unintlen(i);
	(*str)++;
	return (count);
}
