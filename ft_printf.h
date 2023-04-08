/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:15:55 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/09 15:12:38 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<stdio.h>
# include<unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(const char *str);
int	ft_putnbr_base(unsigned long n);
int	ft_putunsigned(unsigned int n);
int	ft_hex(unsigned int n, char str);

#endif