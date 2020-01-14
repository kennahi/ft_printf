/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispecifier2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:07:12 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 20:01:35 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dizeroprecision(int i, t_var *flog)
{
	int count;

	count = 0;
	if (flog->w > intlen(i))
	{
		if (i == -2147483648)
			flog->p = flog->w;
		else if (i < 0)
			flog->p = flog->w - 1;
		else if (i >= 0)
			flog->p = flog->w;
	}
	return (count);
}

void	diconditions(int i, t_var *flog)
{
	if ((flog->flag == 1) && flog->w < intlen(i))
		flog->flag = 0;
	if ((flog->w < 0) && (flog->w * -1) >= intlen(i))
	{
		flog->flag = 1;
		flog->w = flog->w * -1;
	}
}

void	uconditions(unsigned int i, t_var *flog)
{
	if ((flog->flag == 1) && flog->w < unintlen(i))
		flog->flag = 0;
	if ((flog->w < 0) && (flog->w * -1) >= unintlen(i))
	{
		flog->flag = 1;
		flog->w = flog->w * -1;
	}
}

void	sconditions(char *s, t_var *flog)
{
	if ((flog->flag == 1) && flog->w < ft_strlen(s) && flog->p >= ft_strlen(s))
	{
		if (flog->w > 0)
			flog->flag = 0;
		if (flog->w < 0 && (flog->w * -1) < ft_strlen(s))
			flog->w = 0;
	}
	if ((flog->w < 0))
	{
		flog->flag = 1;
		flog->w = flog->w * -1;
	}
	if (flog->w > ft_strlen(s) && flog->p < 0)
		flog->p = flog->w;
}

int		sadditional(char *s, t_var *flog)
{
	int		count;

	count = 0;
	if (flog->flag == 2)
	{
		if (flog->p > 0 && ft_strlen(s) > flog->p)
		{
			if (flog->w >= flog->p)
			{
				flog->w = flog->w - flog->p;
				if (flog->w > 0)
					count += swidth(flog);
			}
		}
		else
		{
			if (flog->w >= ft_strlen(s))
			{
				flog->w -= ft_strlen(s);
				if (flog->w > 0)
					count += swidth(flog);
			}
		}
	}
	return (count);
}
