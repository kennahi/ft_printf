/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pspecifier1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:28:08 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:01:43 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			pwidth(t_var *flog)
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
		ft_putstr("0x");
		while (flog->w > 0)
		{
			ft_putchar('0');
			flog->w--;
			count++;
		}
	}
	return (count);
}

static	void		pconditions(char *s, t_var *flog)
{
	if ((flog->flag == 1) && flog->w <= ft_strlen(s))
		flog->flag = 0;
	if (flog->w < 0)
	{
		flog->flag = 1;
		flog->w *= -1;
	}
}

static	int			conditions(char *s, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->w > ft_strlen(s) && flog->flag != 1)
	{
		flog->w -= ft_strlen(s);
		count += pwidth(flog);
	}
	else if (flog->flag == 2 && flog->w <= ft_strlen(s))
		ft_putstr("0x");
	return (count);
}

int					pspecifier(const char **str, va_list args, t_var *flog)
{
	unsigned long int	i;
	int					count;
	char				*s;

	count = 0;
	i = va_arg(args, unsigned long int);
	s = pconverter(i);
	pconditions(s, flog);
	flog->w -= 2;
	count += conditions(s, flog);
	if (flog->flag != 2)
		ft_putstr("0x");
	ft_putstr(s);
	if (flog->flag == 1)
	{
		flog->w -= ft_strlen(s);
		count += pwidth(flog);
	}
	count += ft_strlen(s) + 2;
	(*str)++;
	free(s);
	return (count);
}
