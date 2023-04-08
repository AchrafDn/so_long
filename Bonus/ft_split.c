/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:51:45 by adadoun           #+#    #+#             */
/*   Updated: 2023/03/21 23:51:47 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	nword(const char *s, char c)
{
	int		nb;
	size_t	i;
	int		j;

	i = 0;
	nb = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
		{
			j++;
		}
		if (j != 0)
		{
			i = i + j;
			nb = nb + 1;
		}
		else
			i++;
	}
	return (nb);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

static char	**ft_result(char **ptr, char *s, char c, int k)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
		{
			ptr[k] = ft_substr(s, i, j);
			if (!ptr[k])
			{
				ft_free(ptr);
				return (NULL);
			}
			i = i + j;
			k++;
		}
		else
			i++;
	}
	ptr[k] = 0;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		nb;

	if (!s)
		return (NULL);
	nb = nword(s, c);
	ptr = malloc(sizeof(char *) * (nb + 1));
	if (!ptr)
		return (NULL);
	return (ft_result(ptr, (char *)s, c, 0));
}
