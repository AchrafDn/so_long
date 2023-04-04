/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 07:39:54 by adadoun           #+#    #+#             */
/*   Updated: 2023/04/03 07:39:55 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_left(t_walls *p)
{
	p->ptr[p->p_y][p->p_x] = '0';
	mlx_put_image_to_window(p->mlx, p->window, p->floor, p->p_x * 60, p->p_y
			* 60);
	p->p_x -= 1;
	if (p->ptr[p->p_y][p->p_x] == 'E' && p->c == 0)
	{
		printf("Number of moves %i\n", p->i + 1);
		exit(EXIT_SUCCESS);
	}
	if (p->ptr[p->p_y][p->p_x] == 'C')
		p->c--;
	p->ptr[p->p_y][p->p_x] = 'P';
	put_image(p, "textures/floor.xpm", p->p_x, p->p_y);
	mlx_put_image_to_window(p->mlx, p->window, p->left, p->p_x * 60, p->p_y
			* 60);
	p->i++;
	printf("Number of moves %i\n", p->i);
}

void	ft_right(t_walls *p)
{
	p->ptr[p->p_y][p->p_x] = '0';
	mlx_put_image_to_window(p->mlx, p->window, p->floor, p->p_x * 60, p->p_y
			* 60);
	p->p_x += 1;
	if (p->ptr[p->p_y][p->p_x] == 'E' && p->c == 0)
	{
		printf("Number of moves %i\n", p->i + 1);
		exit(EXIT_SUCCESS);
	}
	if (p->ptr[p->p_y][p->p_x] == 'C')
		p->c--;
	p->ptr[p->p_y][p->p_x] = 'P';
	put_image(p, "textures/floor.xpm", p->p_x, p->p_y);
	mlx_put_image_to_window(p->mlx, p->window, p->right, p->p_x * 60, p->p_y
			* 60);
	p->i++;
	printf("Number of moves %i\n", p->i);
}

void	ft_up(t_walls *p)
{
	p->ptr[p->p_y][p->p_x] = '0';
	mlx_put_image_to_window(p->mlx, p->window, p->floor, p->p_x * 60, p->p_y
			* 60);
	p->p_y -= 1;
	if (p->ptr[p->p_y][p->p_x] == 'E' && p->c == 0)
	{
		printf("Number of moves %i\n", p->i + 1);
		exit(EXIT_SUCCESS);
	}
	if (p->ptr[p->p_y][p->p_x] == 'C')
		p->c--;
	p->ptr[p->p_y][p->p_x] = 'P';
	put_image(p, "textures/floor.xpm", p->p_x, p->p_y);
	mlx_put_image_to_window(p->mlx, p->window, p->back, p->p_x * 60, p->p_y
			* 60);
	p->i++;
	printf("Number of moves %i\n", p->i);
}

void	ft_down(t_walls *p)
{
	p->ptr[p->p_y][p->p_x] = '0';
	mlx_put_image_to_window(p->mlx, p->window, p->floor, p->p_x * 60, p->p_y
			* 60);
	p->p_y += 1;
	if (p->ptr[p->p_y][p->p_x] == 'E' && p->c == 0)
	{
		printf("Number of moves %i\n", p->i + 1);
		exit(EXIT_SUCCESS);
	}
	if (p->ptr[p->p_y][p->p_x] == 'C')
		p->c--;
	p->ptr[p->p_y][p->p_x] = 'P';
	put_image(p, "textures/floor.xpm", p->p_x, p->p_y);
	mlx_put_image_to_window(p->mlx, p->window, p->front, p->p_x * 60, p->p_y
			* 60);
	p->i++;
	printf("Number of moves %i\n", p->i);
}

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

int	key_hook(int keycode, t_walls *p)
{
	//system("leaks so_long");
	if (keycode == 53)
		exit(0);
	(p->start_on == 0) && (menu_page(keycode, p));
	if (p->start_on != 0)
	{
		if (keycode == 1 && p->ptr[p->p_y + 1][p->p_x] != '1' && (p->ptr[p->p_y
				+ 1][p->p_x] != 'E' || p->c == 0))
			ft_down(p);
		else if (keycode == 13 && p->ptr[p->p_y - 1][p->p_x] != '1'
				&& (p->ptr[p->p_y - 1][p->p_x] != 'E' || p->c == 0))
			ft_up(p);
		else if (keycode == 0 && p->ptr[p->p_y][p->p_x - 1] != '1'
				&& (p->ptr[p->p_y][p->p_x - 1] != 'E' || p->c == 0))
			ft_left(p);
		else if (keycode == 2 && p->ptr[p->p_y][p->p_x + 1] != '1'
				&& (p->ptr[p->p_y][p->p_x + 1] != 'E' || p->c == 0))
			ft_right(p);
	}
	return (0);
}
