/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:52:51 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:52:53 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct walls
{
	int		fd;
	int		w;
	int		h;
	int		p;
	int		e;
	int		c;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		i;
	char	**ptr;
	char	**dup;
	char	*n_moves;
	void	*mlx;
	void	*window;
	void	*image;
	void	*floor;
	void	*colect;
	void	*front;
	void	*back;
	void	*right;
	void	*left;
	int		start_on;
	int		flesh_move;
	int		f_x;
	int		f_y;
	int		index_character;
}			t_walls;
/*create map*/
int		put_image(t_walls *p, char *str, int x, int y);
void	init_character(t_walls *p);
void	create_map(t_walls *p);
int		handle_event(void);
void	start_window(t_walls *p);
/*moves*/
int		key_hook(int keycode, t_walls *p);
/*moves2*/
int		menu_page(int keycode, t_walls *p);
/*parsing*/
void	parsing(char **av, t_walls *p);
/*parssing utils*/
void	func_error(char *str);
void	create2darray(t_walls *ptr_str);
void	rectangular(t_walls *ptr_str);
void	walls(t_walls *ptr_str);
void	flood_fill(char **str, int x, int y);
/*function*/
char	**ft_split(const char *s, char c);
int		ft_strcmp(const char *f, const char *s);
char	*ft_strdup(char *s1);
char	*ft_itoa(int c);
#endif
