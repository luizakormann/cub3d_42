/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:19:59 by lukorman          #+#    #+#             */
/*   Updated: 2026/09/21 23:44:42 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	count_doors(t_data *data);
static void	fill_doors(t_game *game, t_data *data);
void		init_doors(t_game *game, t_data *data);

static int	count_doors(t_data *data)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (data->grid[y])
	{
		x = 0;
		while (data->grid[y][x])
		{
			if (data->grid[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	fill_doors(t_game *game, t_data *data)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (data->grid[y])
	{
		x = 0;
		while (data->grid[y][x])
		{
			if (data->grid[y][x] == 'D')
			{
				game->doors[i].x = x;
				game->doors[i].y = y;
				game->doors[i].is_open = 0;
				game->doors[i].timer = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_doors(t_game *game, t_data *data)
{
	game->door_count = count_doors(data);
	game->doors = NULL;
	if (game->door_count == 0)
		return ;
	game->doors = malloc(sizeof(t_door) * game->door_count);
	if (!game->doors)
	{
		game->door_count = 0;
		return ;
	}
	fill_doors(game, data);
}
