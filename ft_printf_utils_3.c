/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:19:05 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/10 19:38:15 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		intlen(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int		unintlen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (!*s || start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (!(substring = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (start == i)
		{
			while (j < len && s[i])
				substring[j++] = s[i++];
			substring[j] = '\0';
			return (substring);
		}
		i++;
	}
	return (NULL);
}
