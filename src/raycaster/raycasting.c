/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 23:17:55 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/08 00:01:18 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
