/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:13:52 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/20 00:53:48 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
			ray->tex_id = TEX_SO;
		else
			ray->tex_id = TEX_NO;
	}
}

static int	get_texture_pixel(t_image *tex, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	pixel = tex->addr + (y * tex->line_length)
		+ (x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

static int	compute_tex_x(t_ray *ray, t_image *tex)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * (double)tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	t_image	*tex;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;

	setup_wall_calc(game, ray);
	set_tex_id(ray);
	tex = &game->textures[ray->tex_id];
	tex_x = compute_tex_x(ray, tex);
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = ray->draw_start - game->image.height / 2 + ray->line_height / 2;
	tex_pos *= step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->image, x, y,
			get_texture_pixel(tex, tex_x, (int)tex_pos));
		tex_pos += step;
		y++;
	}
}
