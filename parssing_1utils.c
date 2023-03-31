/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_1utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:54:24 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:54:25 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	func_error(char *str)
{
	printf("Error\n%s", str);
	exit(1);
}

void	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			func_error("Last line is empty");
		i++;
	}
}

void	create2darray(t_walls *p)
{
	char	*str;
	char	*str1;
	int		i;

	str = NULL;
	str1 = get_next_line(p->fd);
	if (str1 == NULL || str1[0] == '\n')
		func_error("Map not valid (empty map or first line is empty)");
	while (str1 != NULL)
	{
		str = ft_strjoin(str, str1);
		str1 = get_next_line(p->fd);
		if (str1 && str1[0] == '\n')
			func_error("Empty line");
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			func_error("Last line is empty");
	}
	p->ptr = ft_split(str, '\n');
}

void	rectangular(t_walls *p)
{
	int	i;

	p->h = 0;
	p->w = ft_strlen(p->ptr[0]);
	while (p->ptr[p->h])
		p->h++;
	i = 0;
	while (i < p->h)
	{
		if ((int)ft_strlen(p->ptr[i]) != p->w)
			func_error("Not rectangular");
		i++;
	}
}

void	format_ber(char *str)
{
	int	len;
	int	i;
	int	v;

	v = 0;
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] && str[i + 1] != '/')
			v++;
		i++;
	}
	if (v != 1)
		func_error("format is not .ber");
	if (ft_strcmp(str + len - 4, ".ber") != 0)
		func_error("format is not .ber");
}
