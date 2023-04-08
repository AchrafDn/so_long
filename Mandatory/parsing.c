/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:54:04 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:54:06 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	func_error(char *str)
{
	ft_printf("Error\n%s", str);
	exit(1);
}

void	format_ber(char *str)
{
	int	i;
	int	v;

	v = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] && str[i + 1] != '/')
			v++;
		i++;
	}
	if (v != 1)
		func_error("format is not .ber");
	if (ft_strcmp(str + ft_strlen(str) - 4, ".ber") != 0)
		func_error("format is not .ber");
}

char	**dup_2darray(t_walls *p)
{
	int	i;

	i = 0;
	p->dup = malloc(p->h * (sizeof(char **) + 1));
	if (!p->dup)
		func_error("Malloc failed");
	while (i < p->h)
	{
		p->dup[i] = ft_strdup(p->ptr[i]);
		i++;
	}
	p->dup[i] = NULL;
	return (p->dup);
}

void	check_flood_fill(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][++j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'P' || str[i][j] == 'E')
				func_error("You can't access all characters");
		}
	}
}

void	parsing(char **av, t_walls *p)
{
	char	**str;

	p->fd = open(av[1], O_RDONLY);
	if (p->fd < 0)
		func_error("open file");
	format_ber(av[1]);
	create2darray(p);
	rectangular(p);
	walls(p);
	str = dup_2darray(p);
	flood_fill(str, p->p_y, p->p_x);
	check_flood_fill(str);
}
