/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 23:12:38 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 21:26:16 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# include "game_bonus.h"
# include <math.h>

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	t_tex_id	tex_id;
	int			is_door;
}	t_ray;

void	init_ray(t_game *game, t_ray *ray, int x);
void	perform_dda(t_game *game, t_ray *ray);
void	draw_wall(t_game *game, t_ray *ray, int x);
void	render_rays(t_game *game);

#endif