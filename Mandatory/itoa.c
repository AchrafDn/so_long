/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:54:05 by adadoun           #+#    #+#             */
/*   Updated: 2022/10/31 23:14:16 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static size_t	nchar(int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		i = 1;
		c = -c;
	}
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static char	*ft_result(char *p, int c)
{
	int		signe;
	size_t	i;

	i = nchar(c);
	signe = 0;
	p[i] = '\0';
	if (c < 0)
	{
		c = -c;
		signe = -1;
	}
	if (i > 0)
		i--;
	while (i > 0)
	{
		p[i] = c % 10 + 48;
		c = c / 10;
		if (i >= 0)
			i--;
	}
	if (signe == -1)
		p[i] = '-';
	else
		p[i] = c + 48;
	return (p);
}

char	*ft_itoa(int c)
{
	char	*p;

	if (c == -2147483648)
	{
		p = ft_substr("-2147483648", 0, 11);
		return (p);
	}
	p = malloc(nchar(c) + 1);
	if (!p)
		return (NULL);
	p = ft_result(p, c);
	return (p);
}
