/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:07:09 by luiza             #+#    #+#             */
/*   Updated: 2026/09/21 20:20:32 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"

int	is_wall(t_game *game, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= game->map.height || mx < 0)
		return (1);
	if (mx >= (int)ft_strlen(game->map.grid[my]))
		return (1);
	return (game->map.grid[my][mx] == '1' || game->map.grid[my][mx] == ' ');
}
