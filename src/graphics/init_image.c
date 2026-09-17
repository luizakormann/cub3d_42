/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 23:36:26 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/16 03:06:13 by kaidda-s         ###   ########.fr       */
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

static int load_texture(void *mlx_ptr, t_image *img, char *path) {
    img->ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img->width, &img->height);
    if (!img->ptr) 
        return (1);
    img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
            &img->line_length, &img->endian);
    if (!img->addr)
        return (1);
    return (0);
}
