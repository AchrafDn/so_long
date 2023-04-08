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

#include "../header.h"

void	init_mlx(t_walls *p)
{
	int	x;
	int	y;

	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, p->w * 60, p->h * 60, "42 game");
	p->floor = mlx_xpm_file_to_image(p->mlx, "textures/floor.xpm", &x, &y);
	p->flesh_move = 0;
	p->index_character = 0;
	p->start_on = 0;
}

int	main(int ac, char **av)
{
	t_walls	p;

	if (ac != 2)
		func_error("Arguments");
	parsing(av, &p);
	init_mlx(&p);
	start_window(&p);
}
