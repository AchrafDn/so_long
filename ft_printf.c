/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:00 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/09 15:29:39 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		len += 1;
	}
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

int	ft_putnbr_base(size_t n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_putnbr_base(n / 16);
		len += ft_putnbr_base(n % 16);
	}
	else
		len += write(1, &base[n % 16], 1);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_resultat(const char *str, int i, va_list varg)
{
	int	rlen;

	rlen = 0;
	if (str[i + 1] == 'c')
		rlen += ft_putchar(va_arg(varg, int));
	else if (str[i + 1] == 's')
		rlen += ft_putstr(va_arg(varg, char *));
	else if (str[i + 1] == 'i' || str[i + 1] == 'd')
		rlen += ft_putnbr(va_arg(varg, int));
	else if (str[i + 1] == 'u')
		rlen += ft_putunsigned(va_arg(varg, unsigned int));
	else if (str[i + 1] == 'p')
		rlen += write(1, "0x", 2) + ft_putnbr_base(va_arg(varg, size_t));
	else if (str[i + 1] == 'X' || str[i + 1] == 'x')
		rlen += ft_hex(va_arg(varg, unsigned int), str[i + 1]);
	else if (str[i + 1] == '%')
		rlen += write(1, "%", 1);
	return (rlen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rlen;
	va_list	varg;

	va_start(varg, str);
	rlen = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			rlen += ft_resultat(str, i, varg);
			i++;
		}
		else
			rlen += ft_putchar(str[i]);
	}
	return (rlen);
}
