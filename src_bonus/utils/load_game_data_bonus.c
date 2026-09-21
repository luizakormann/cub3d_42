/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_data_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:39:05 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 20:21:40 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data_bonus.h"

static void	set_player_direction(t_camera *player, char direction)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	if (direction == 'N')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1.0;
		player->plane_y = 0.66;
	}
	else
	{
		player->dir_x = -1.0;
		player->plane_y = -0.66;
	}
}

void	load_game_data(t_game *game, t_data *data)
{
	game->map.grid = data->grid;
	game->map.height = map_height(data->grid);
	game->map.width = map_width(data->grid, game->map.height);
	game->floor_color = data->floor_color;
	game->ceiling_color = data->ceiling_color;
	game->player.pos_x = data->player.x + 0.5;
	game->player.pos_y = data->player.y + 0.5;
	set_player_direction(&game->player, data->player.dir);
}
