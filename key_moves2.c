/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 07:39:54 by adadoun           #+#    #+#             */
/*   Updated: 2023/04/03 07:39:55 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	flesh_down(t_walls *p)
{
	put_image(p, "textures/floor.xpm", p->f_x, p->f_y);
	p->flesh_move++;
	p->f_y++;
	put_image(p, "textures/flesh.xpm", p->f_x, p->f_y);
}

void	flesh_up(t_walls *p)
{
	put_image(p, "textures/floor.xpm", p->f_x, p->f_y);
	p->flesh_move--;
	p->f_y--;
	put_image(p, "textures/flesh.xpm", p->f_x, p->f_y);
}

int	choose_character(int keycode, t_walls *p)
{
	if (keycode == 2)
	{
		put_image(p, "textures/floor.xpm", (p->w / 2), (p->h / 2) + 1);
		put_image(p, "textures/girl.xpm", (p->w / 2), (p->h / 2) + 1);
		(p->index_character == 0) && (p->index_character = 1);
	}
	else if (keycode == 0)
	{
		put_image(p, "textures/floor.xpm", (p->w / 2), (p->h / 2) + 1);
		put_image(p, "textures/front.xpm", (p->w / 2), (p->h / 2) + 1);
		(p->index_character == 1) && (p->index_character = 0);
	}
	return (0);
}

int	menu_page(int keycode, t_walls *p)
{
	if (keycode == 36)
	{
		if (p->flesh_move == 0)
		{
			p->start_on = 1;
			create_map(p);
		}
		else if (p->flesh_move == 1)
			exit(0);
	}
	else if (keycode == 1 && p->flesh_move <= 1)
		flesh_down(p);
	else if (keycode == 13 && p->flesh_move >= 1)
		flesh_up(p);
	(p->flesh_move == 2) && (choose_character(keycode, p));
	return (0);
}
