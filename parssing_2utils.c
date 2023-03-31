/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_2utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:54:33 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:54:35 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	if (str[x][y] != 'E' && str[x][y] != 'C' && str[x][y] != '0'
		&& str[x][y] != 'P')
		return ;
	str[x][y] = 'F';
	flood_fill(str, x + 1, y);
	flood_fill(str, x - 1, y);
	flood_fill(str, x, y + 1);
	flood_fill(str, x, y - 1);
	return ;
}
