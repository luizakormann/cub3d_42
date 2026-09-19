/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:26:40 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:32:26 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

int	map_height(char **grid);
int	map_width(char **grid, int height);

int	map_height(char **grid)
{
	int	h;

	h = 0;
	while (grid && grid[h])
		h++;
	return (h);
}

int	map_width(char **grid, int height)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < height)
	{
		len = ft_strlen(grid[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
