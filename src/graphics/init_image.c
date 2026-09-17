/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 23:36:26 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/17 00:02:59 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"
#include <stddef.h>

int	init_image(t_game *game)
{
	game->image.width = WINDOW_WIDTH;
	game->image.height = WINDOW_HEIGHT;
	game->image.ptr = mlx_new_image(game->mlx_ptr,
			game->image.width, game->image.height);
	if (!game->image.ptr)
		return (1);
	game->image.addr = mlx_get_data_addr(game->image.ptr,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
	if (!game->image.addr)
	{
		mlx_destroy_image(game->mlx_ptr, game->image.ptr);
		game->image.ptr = NULL;
		return (1);
	}
	return (0);
}
