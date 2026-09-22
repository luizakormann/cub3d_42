/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:07:09 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/21 21:34:21 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"
#include "bonus.h"

int	is_wall(t_game *game, double x, double y)
{
	int		mx;
	int		my;
	char	c;
	t_door	*door;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || my >= game->map.height || mx < 0)
		return (1);
	if (mx >= (int)ft_strlen(game->map.grid[my]))
		return (1);
	c = game->map.grid[my][mx];
	if (c == 'D')
	{
		door = get_door(game, mx, my);
		return (!(door && door->is_open));
	}
	return (c == '1' || c == ' ');
}
