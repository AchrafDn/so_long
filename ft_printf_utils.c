/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:28:51 by adadoun           #+#    #+#             */
/*   Updated: 2023/04/08 07:28:54 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char str)
{
	char	*base;
	int		len;

	len = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	else if (str == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_hex(n / 16, str);
		len += ft_hex(n % 16, str);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	if (n <= 9 && n >= 0)
	{
		n = n + 48;
		len += write(1, &n, 1);
	}
	return (len);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
