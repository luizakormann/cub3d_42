/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:29:02 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/19 00:30:42 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

static double	char_to_angle(char c);
static void		scan_row(t_data *data, int y, int *count);
int				find_player(t_data *data);

static double	char_to_angle(char c)
{
	if (c == 'N')
		return (-PI / 2);
	if (c == 'S')
		return (PI / 2);
	if (c == 'E')
		return (0);
	return (PI);
}

static void	scan_row(t_data *data, int y, int *count)
{
	int	x;

	x = 0;
	while (data->grid[y][x])
	{
		if (data->grid[y][x] == 'N' || data->grid[y][x] == 'S'
			|| data->grid[y][x] == 'E' || data->grid[y][x] == 'W')
		{
			data->player.x = x;
			data->player.y = y;
			data->player.dir = data->grid[y][x];
			data->player.angle = char_to_angle(data->grid[y][x]);
			(*count)++;
		}
		x++;
	}
}

int	find_player(t_data *data)
{
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (data->grid[y])
	{
		scan_row(data, y, &count);
		y++;
	}
	if (count != 1)
	{
		print_error("Map must contain exactly one player spawn");
		return (-1);
	}
	return (0);
}
