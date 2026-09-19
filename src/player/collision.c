/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:07:09 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:36:40 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

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
