/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:19:59 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/21 21:20:25 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	count_doors(t_data *data);
static void	fill_doors(t_game *game, t_data *data);
void		init_doors(t_game *game, t_data *data);
t_door		*get_door(t_game *game, int x, int y);
void		toggle_door(t_game *game);
void		update_doors(t_game *game);

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

t_door	*get_door(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (&game->doors[i]);
		i++;
	}
	return (NULL);
}

void	toggle_door(t_game *game)
{
	int		fx;
	int		fy;
	t_door	*door;

	fx = (int)(game->player.pos_x + game->player.dir_x);
	fy = (int)(game->player.pos_y + game->player.dir_y);
	door = get_door(game, fx, fy);
	if (!door)
		return ;
	if (door->is_open)
	{
		door->is_open = 0;
		door->timer = 0;
	}
	else
	{
		door->is_open = 1;
		door->timer = DOOR_OPEN_TIME;
	}
}

void	update_doors(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].is_open && game->doors[i].timer > 0)
		{
			game->doors[i].timer--;
			if (game->doors[i].timer == 0)
				game->doors[i].is_open = 0;
		}
		i++;
	}
}
