/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:56:19 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/06 02:50:04 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(copy = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int		length(int n, int sign)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (((len == 0) ? 1 : len) + sign);
}

static char		*itoo(int len, int sign, int n)
{
	char	*a;

	if (!(a = (char *)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	a[len] = '\0';
	while (--len >= sign)
	{
		a[len] = n % 10 + 48;
		n = n / 10;
	}
	if (len >= 0)
		a[len] = '-';
	return (a);
}

void			ft_itoa(int n)
{
	int		len;
	char	*a;
	int		sign;

	len = 0;
	sign = 0;
	if (n == -2147483648)
	{
		a = ft_strdup("2147483648");
		ft_putstr(a);
		free(a);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	len = length(n, sign);
	a = itoo(len, sign, n);
	ft_putstr(a);
	free(a);
}

void			ft_itoaa(unsigned int n)
{
	int				len;
	char			*a;
	unsigned int	num;

	len = 0;
	num = n;
	if (num == 0)
		len++;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	if (!(a = (char *)malloc((sizeof(char) * (len + 1)))))
		return ;
	a[len] = '\0';
	while (--len >= 0)
	{
		a[len] = n % 10 + 48;
		n = n / 10;
	}
	ft_putstr(a);
	free(a);
}
