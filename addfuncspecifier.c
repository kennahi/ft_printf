/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfuncspecifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:34:49 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 19:07:15 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			sadditional2(char *s, t_var *flog)
{
	int		count;
	char	*str;

	count = 0;
	if (flog->p > 0)
	{
		str = ft_substr(s, 0, flog->p);
		ft_putstr(str);
		count += ft_strlen(str);
		free(str);
	}
	else if (flog->p < 0)
	{
		ft_putstr(s);
		count += ft_strlen(s);
	}
	return (count);
}

int			dadditional2(int i)
{
	int		count;

	count = 0;
	ft_putchar('-');
	if (i != -2147483648)
		count++;
	i = i * -1;
	return (count);
}

void		xadditional2(char *s, t_var *flog)
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
}
