/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 23:18:30 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 23:52:55 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"
#include "bonus.h"

static int	check_hit(t_game *game, t_ray *ray)
{
	char	c;
	t_door	*door;

	c = game->map.grid[ray->map_y][ray->map_x];
	if (c == '1')
		return (1);
	if (c == 'D')
	{
		door = get_door(game, ray->map_x, ray->map_y);
		if (door && door->is_open)
			return (0);
		ray->is_door = 1;
		return (1);
	}
	return (0);
}

void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	ray->is_door = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		hit = check_hit(game, ray);
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}
