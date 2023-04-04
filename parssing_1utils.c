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
		free(str1);
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
	free(str);
	free(str1);
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

void	characters(t_walls *p, int i)
{
	int	j;

	j = 0;
	while (++j < p->w - 1)
	{
		if (p->ptr[i][j] == 'P')
		{
			p->p_x = j;
			p->p_y = i;
			p->p++;
		}
		else if (p->ptr[i][j] == 'E')
			p->e++;
		else if (p->ptr[i][j] == 'C')
			p->c++;
		else if (p->ptr[i][j] != '0' && p->ptr[i][j] != '1')
			func_error("Different character");
	}
}

void	walls(t_walls *p)
{
	int	i;

	i = 0;
	while (i < p->w)
	{
		if (p->ptr[0][i] != '1' || p->ptr[p->h - 1][i] != '1')
			func_error("Not valid map(walls)");
		i++;
	}
	i = 1;
	p->e = 0;
	p->p = 0;
	p->c = 0;
	while (i < p->h - 1)
	{
		if (p->ptr[i][0] != '1' || p->ptr[i][p->w - 1] != '1')
			func_error("Not valid map(walls)");
		characters(p, i);
		i++;
	}
	if (p->e != 1 || p->p != 1 || p->c < 1)
		func_error("Map not valid (Charachters)");
}

void	flood_fill(char **str, int x, int y)
{
	if (str[x][y] != 'C' && str[x][y] != '0' && str[x][y] != 'P'
		&& str[x][y] != 'E')
		return ;
	if (str[x][y] == 'E')
	{
		str[x][y] = 'e';
		return ;
	}
	str[x][y] = 'F';
	flood_fill(str, x + 1, y);
	flood_fill(str, x - 1, y);
	flood_fill(str, x, y + 1);
	flood_fill(str, x, y - 1);
	return ;
}