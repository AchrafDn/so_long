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

int	put_image(t_walls *p, char *str, int x, int y)
{
	int	pixel;

	pixel = 60;
	p->image = mlx_xpm_file_to_image(p->mlx, str, &pixel, &pixel);
	mlx_put_image_to_window(p->mlx, p->window, p->image, x * 60, y * 60);
	return (0);
}

int	handle_event(void)
{
	exit(0);
	return (0);
}

void	init_character(t_walls *p)
{
	int	pixel;

	pixel = 60;
	if (p->index_character == 1)
	{
		p->front = mlx_xpm_file_to_image(p->mlx,"textures/1/girl.xpm",&pixel,&pixel);
		p->right = mlx_xpm_file_to_image(p->mlx, "textures/1/right.xpm", &pixel, &pixel);
		p->left = mlx_xpm_file_to_image(p->mlx, "textures/1/left.xpm", &pixel, &pixel);
		p->back = mlx_xpm_file_to_image(p->mlx, "textures/1/back.xpm", &pixel, &pixel);
	}
	else if (p->index_character == 0)
	{
		p->front = mlx_xpm_file_to_image(p->mlx,"textures/front.xpm",&pixel,&pixel);
		p->right = mlx_xpm_file_to_image(p->mlx, "textures/right.xpm", &pixel, &pixel);
		p->left = mlx_xpm_file_to_image(p->mlx, "textures/left.xpm", &pixel, &pixel);
		p->back = mlx_xpm_file_to_image(p->mlx, "textures/back.xpm", &pixel, &pixel);
	}
}
void	create_map(t_walls *p)
{
	init_character(p);
	p->y = -1; //cause mlx_xpm_file_to_image change the value of x and y
	p->i = 0;  // initialize number of moves
	while (++p->y < p->h)
	{
		p->x = -1;
		while (++p->x < p->w)
		{
			if (p->ptr[p->y][p->x] == '0' || p->ptr[p->y][p->x] == 'E' ||
				p->ptr[p->y][p->x] == 'P' || p->ptr[p->y][p->x] == 'C')
				mlx_put_image_to_window(p->mlx, p->window, p->floor, p->x * 60,
						p->y * 60);
			(p->ptr[p->y][p->x] == '1') && (put_image(p, "textures/walls.xpm",
						p->x, p->y));
			(p->ptr[p->y][p->x] == 'C') && (put_image(p,
						"textures/colectible.xpm", p->x, p->y));
			(p->ptr[p->y][p->x] == 'E') && (put_image(p, "textures/exit.xpm",
						p->x, p->y));
			if (p->ptr[p->y][p->x] == 'P')
				mlx_put_image_to_window(p->mlx, p->window, p->front, p->p_x
						* 60, p->p_y * 60);
		}
	}
}

void	init_mlx(t_walls *p)
{
	int	x;
	int	y;

	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, p->w * 60, p->h * 60, "42 game");
	p->floor = mlx_xpm_file_to_image(p->mlx, "textures/floor.xpm", &x, &y);
	/***************/
	p->front = mlx_xpm_file_to_image(p->mlx, "textures/front.xpm", &x, &y);
	p->back = mlx_xpm_file_to_image(p->mlx, "textures/back.xpm", &x, &y);
	p->right = mlx_xpm_file_to_image(p->mlx, "textures/right.xpm", &x, &y);
	p->left = mlx_xpm_file_to_image(p->mlx, "textures/left.xpm", &x, &y);
}

void	start_window(t_walls *p)
{
	p->f_x = (p->w / 2) - 2;
	p->f_y = (p->h / 2) - 1;
	p->y = -1;
	//cause mlx_xpm_file_to_image change the value of x and y
	p->i = 0; // initialize number of moves
	p->start_on = 0;
	while (++p->y < p->h)
	{
		p->x = -1;
		while (++p->x < p->w)
			put_image(p, "textures/floor.xpm", p->x, p->y);
	}
	p->flesh_move = 0;
	p->index_character = 0;
	put_image(p, "textures/exit_button.xpm", (p->w / 2) - 1, (p->h / 2));
	put_image(p, "textures/start.xpm", (p->w / 2) - 1, (p->h / 2) - 1);
	put_image(p, "textures/front.xpm", (p->w / 2), (p->h / 2) + 1);
	put_image(p, "textures/flesh.xpm", p->f_x, p->f_y);
	mlx_hook(p->window, 17, 0, handle_event, NULL);
	mlx_key_hook(p->window, key_hook, p);
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	t_walls	p;

	if (ac != 2)
		func_error("Arguments\n");
	parsing(av, &p);
	init_mlx(&p);
	start_window(&p);
}
