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
	p->n_moves = ft_itoa(p->i);
	printf("Number of moves %s\n", p->n_moves);
	put_image(p, "textures/walls.xpm", 0, 0);
	mlx_string_put(p->mlx, p->window, 0, 0, 0xFFFFFF, p->n_moves);
	free(p->n_moves);
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
	p->n_moves = ft_itoa(p->i);
	printf("Number of moves %s\n", p->n_moves);
	put_image(p, "textures/walls.xpm", 0, 0);
	mlx_string_put(p->mlx, p->window, 0, 0, 0xFFFFFF, p->n_moves);
	free(p->n_moves);
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
	p->n_moves = ft_itoa(p->i);
	printf("Number of moves %s\n", p->n_moves);
	put_image(p, "textures/walls.xpm", 0, 0);
	mlx_string_put(p->mlx, p->window, 0, 0, 0xFFFFFF, p->n_moves);
	free(p->n_moves);
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
	p->n_moves = ft_itoa(p->i);
	printf("Number of moves %s\n", p->n_moves);
	put_image(p, "textures/walls.xpm", 0, 0);
	mlx_string_put(p->mlx, p->window, 0, 0, 0xFFFFFF, p->n_moves);
	free(p->n_moves);
}

int	key_hook(int keycode, t_walls *p)
{
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
