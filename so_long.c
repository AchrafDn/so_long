/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:08:46 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/27 01:08:47 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_image(t_walls *p, char *str, int x, int y)
{
	int	pixel;

	pixel = 60;
	p->image = mlx_xpm_file_to_image(p->mlx, str, &pixel, &pixel);
	mlx_put_image_to_window(p->mlx, p->window, p->image, x * 60, y * 60);
}

void	move(t_walls *p, int keycode, int n)
{
	p->ptr[p->p_y][p->p_x] = '0';
	mlx_put_image_to_window(p->mlx, p->window, p->floor, p->p_x * 60, p->p_y
		* 60);
	if (keycode == 0 || keycode == 2)
		p->p_x += n;
	else if (keycode == 1 || keycode == 13)
			p->p_y = p->p_y + n;
	p->ptr[p->p_y][p->p_x] = 'P';
	mlx_put_image_to_window(p->mlx, p->window, p->chara, p->p_x * 60, p->p_y
		* 60);
	p->i++;
	printf("Number of moves %i\n", p->i);
}

int	key_hook(int keycode, t_walls *p)
{
	int	pixel;

	pixel = 60;
	if (keycode == 1 && p->ptr[p->p_y + 1][p->p_x] != '1')
		move(p, keycode, 1);
	else if (keycode == 13 && p->ptr[p->p_y - 1][p->p_x] != '1')
		move(p, keycode, -1);
	else if (keycode == 0 && p->ptr[p->p_y][p->p_x - 1] != '1')
		move(p, keycode, -1);
	else if (keycode == 2 && p->ptr[p->p_y][p->p_x + 1] != '1')
		move(p, keycode, 1);
	return (0);
}

void	create_map(t_walls *p)
{
	int	x;
	int	y;

	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, p->w * 60, p->h * 60, "42 game");
	p->chara = mlx_xpm_file_to_image(p->mlx, "textures/character.xpm", &x, &y);
	p->floor = mlx_xpm_file_to_image(p->mlx, "textures/floor.xpm", &x, &y);
	p->colect = mlx_xpm_file_to_image(p->mlx, "textures/floor.xpm", &x, &y);
	p->y = -1; //cause mlx_xpm_file_to_image change the value of x and y
	p->i = 0; // initialize number of moves
	while (++p->y < p->h)
	{
		p->x = -1;
		while (++p->x < p->w)
		{
			if (p->ptr[p->y][p->x] == '0')
				put_image(p, "textures/floor.xpm", p->x, p->y);
			else if (p->ptr[p->y][p->x] == '1')
				put_image(p, "textures/walls.xpm", p->x, p->y);
			if (p->ptr[p->y][p->x] == 'P')
				put_image(p, "textures/character.xpm", p->x, p->y);
		}
	}
	mlx_key_hook(p->window, key_hook, p);
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	t_walls	p;

	if (ac != 2)
		func_error("Arguments");
	parsing(av, &p);
	create_map(&p);
}
