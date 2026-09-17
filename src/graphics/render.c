/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:25:52 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/16 18:39:51 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "game.h"
#include "raycasting.h"
#include "mlx.h"
#include "player.h"

static void	render_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < game->image.height)
	{
		if (y < game->image.height / 2)
			color = game->ceiling_color;
		else
			color = game->floor_color;
		x = 0;
		while (x < game->image.width)
		{
			put_pixel(&game->image, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(game);
	render_background(game);
	render_rays(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window,
		game->image.ptr, 0, 0);
	return (0);
}
