/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:59:42 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/08 00:00:26 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx.h"
#include <stdlib.h>
#include "game.h"

int	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->window = init_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3D");
	if (!game->window)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
		return (1);
	}
	return (0);
}

void	destroy_graphics(t_game *game)
{
	if (game->image.ptr)
		mlx_destroy_image(game->mlx_ptr, game->image.ptr);
	if (game->window)
		mlx_destroy_window(game->mlx_ptr, game->window);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}
