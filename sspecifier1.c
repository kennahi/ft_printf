/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sspecifier1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 02:04:52 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:05:59 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					swidth(t_var *flog)
{
	int		count;

	count = 0;
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

static	int			swidthhigher(char *s, t_var *flog)
{
	int count;

	count = 0;
	if (flog->w >= ft_strlen(s))
	{
		flog->w = flog->w - ft_strlen(s);
		if (flog->flag != 1)
			count += swidth(flog);
	}
	else if (flog->w < ft_strlen(s) && flog->p >= ft_strlen(s))
		flog->w = 0;
	return (count);
}

static	int			sprecisionhigher(char *s, t_var *flog)
{
	int count;

	count = 0;
	if (flog->w >= ft_strlen(s))
	{
		if (flog->p > 0 && ft_strlen(s) > flog->p)
			flog->w = flog->w - flog->p;
		else
			flog->w = flog->w - ft_strlen(s);
		if (flog->flag != 1)
			count += swidth(flog);
	}
	else if (flog->w < ft_strlen(s) && flog->p > 0)
	{
		flog->w -= flog->p;
		if (flog->flag != 1)
			count += swidth(flog);
	}
	return (count);
}

static	int			conditions(char *s, t_var *flog)
{
	int		count;

	count = 0;
	count += sadditional(s, flog);
	if (flog->p >= ft_strlen(s))
		count += swidthhigher(s, flog);
	else if (flog->p < ft_strlen(s))
		count += sprecisionhigher(s, flog);
	return (count);
}

int					sspecifier(const char **str, va_list args, t_var *flog)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	sconditions(s, flog);
	if (flog->p == 0)
	{
		(*str)++;
		count += swidth(flog);
		return (count);
	}
	count += conditions(s, flog);
	count += sadditional2(s, flog);
	if (flog->flag == 1 && flog->p > 0)
		count += swidth(flog);
	(*str)++;
	return (count);
}
