/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:13:52 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/22 00:00:22 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"
#include "bonus.h"

static void	setup_wall_calc(t_game *game, t_ray *ray)
{
	ray->line_height = (int)(game->image.height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->image.height / 2;
	ray->draw_end = ray->line_height / 2 + game->image.height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->image.height)
		ray->draw_end = game->image.height - 1;
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	set_tex_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex_id = TEX_WE;
		else
			ray->tex_id = TEX_EA;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex_id = TEX_NO;
		else
			ray->tex_id = TEX_SO;
	}
}

static void	draw_door_slice(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->image, x, y, DOOR_COLOR);
		y++;
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_image	*tex;

	setup_wall_calc(game, ray);
	if (ray->is_door)
	{
		draw_door_slice(game, ray, x);
		return ;
	}
	set_tex_id(ray);
	tex = &game->textures[ray->tex_id];
	draw_texture_slice(game, ray, tex, x);
}
