/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:13:52 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/08 23:14:36 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	set_wall_limits(t_game *game, t_ray *ray)
{
	ray->line_height = (int)(game->image.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->image.height / 2;
	ray->draw_end = ray->line_height / 2 + game->image.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->image.height)
		ray->draw_end = game->image.height - 1;
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	y;

	set_wall_limits(game, ray);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->image, x, y, WALL_COLOR);
		y++;
	}
}
