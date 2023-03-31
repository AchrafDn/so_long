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
	int		p_x;// index x of player
	int		p_y;// index y of player
	int		x;// map index
	int		y;// map index
	int		i;//number of moves
	char	**ptr;
	char	**dup;
	void	*mlx;
	void	*window;
	void	*image;
	void	*floor;
	void	*chara;
	void	*colect;
}			t_walls;

void		parsing(char **av, t_walls *p);
/*parssing utils*/
void		func_error(char *str);
void		create2darray(t_walls *ptr_str);
void		rectangular(t_walls *ptr_str);
void		format_ber(char *str);
/*parssing utils2*/
void		walls(t_walls *ptr_str);
void		flood_fill(char **str, int x, int y);
/*function*/
char		**ft_split(const char *s, char c);
int			ft_strcmp(const char *f, const char *s);
char		*ft_strdup(char *s1);
#endif
