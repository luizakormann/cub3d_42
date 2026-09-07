/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:25:52 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/06 00:02:44 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx.h"

static void	render_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < game->image.height)
	{
		if (y < game->image.height / 2)
			color = CEILING_COLOR;
		else
			color = FLOOR_COLOR;
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
	render_background(game);
	mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->image.ptr, 0, 0);
	return (0);
}
