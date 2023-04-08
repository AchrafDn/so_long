/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:52:09 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:52:11 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_strcmp(const char *f, const char *s)
{
	size_t	i;

	i = 0;
	while (f[i])
	{
		if (f[i] == s[i])
			i++;
		else
			return ((unsigned char)f[i] - (unsigned char)s[i]);
	}
	return (0);
}
