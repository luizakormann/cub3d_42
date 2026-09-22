/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 00:00:00 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 20:21:06 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include <stddef.h>

void	init_map(t_game *game)
{
	static char	*map[] = {
		"1111111",
		"1000001",
		"1000001",
		"1000001",
		"1000001",
		"1111111",
		NULL
	};

	game->map.grid = map;
	game->map.width = 7;
	game->map.height = 6;
}
