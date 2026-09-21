/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 23:17:55 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 20:21:19 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	render_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < game->image.width)
	{
		init_ray(game, &ray, x);
		perform_dda(game, &ray);
		draw_wall(game, &ray, x);
		x++;
	}
}
