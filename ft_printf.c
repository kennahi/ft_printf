/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:02:15 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:00:44 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			minuszero(const char **str, t_var *flog)
{
	flog->flag = 0;
	if (**str == '-')
	{
		(*str)++;
		flog->flag = 1;
		while (**str == '-' || **str == '0')
			(*str)++;
	}
	else if (**str == '0')
	{
		(*str)++;
		while (**str == '0')
			(*str)++;
		flog->flag = 2;
		if (**str == '-')
		{
			(*str)++;
			flog->flag = 1;
		}
		while (**str == '0' || **str == '-')
			(*str)++;
	}
}

static void			width(const char **str, t_var *flog, va_list args)
{
	flog->w = 0;
	if ('0' <= **str && **str <= '9')
	{
		flog->w = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		flog->w = va_arg(args, int);
		(*str)++;
	}
}

static void			precision(const char **str, va_list args, t_var *flog)
{
	if (**str == '.')
	{
		flog->p = 0;
		(*str)++;
		if ('0' <= **str && **str <= '9')
		{
			flog->p = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			flog->p = va_arg(args, int);
			(*str)++;
		}
	}
	else
		flog->p = -1;
}

static	int			checker(const char **str, va_list args, t_var *flag)
{
	int		count;

	count = 0;
	if ((**str == 'd') || (**str == 'i'))
		count += dispecifier(str, args, flag);
	else if (**str == 'u')
		count += uspecifier(str, args, flag);
	else if (**str == 's')
		count += sspecifier(str, args, flag);
	else if ((**str == 'c') || (**str == '%'))
		count += cspecifier(str, args, flag);
	else if ((**str == 'x') || (**str == 'X'))
		count += xspecifier(str, args, flag);
	else if (**str == 'p')
		count += pspecifier(str, args, flag);
	return (count);
}

int					ft_printf(const char *str, ...)
{
	va_list args;
	int		count;
	t_var	flag;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar(*str);
			count++;
			str++;
		}
		if (*str == '%')
		{
			str++;
			minuszero(&str, &flag);
			width(&str, &flag, args);
			precision(&str, args, &flag);
			count += checker(&str, args, &flag);
		}
	}
	va_end(args);
	return (count);
}
